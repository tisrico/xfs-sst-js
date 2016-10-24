const trans_section = require('./trans_section.js').trans_section;
const data_structure = require('./data_structure.js').data_structure;
const named_code = require('./named_code.js').named_code;

const fs = require('fs');
const path = require('path');
const util = require('util');

var files = process.argv.slice(3);
var option = process.argv[2];

var gTranslators = [];

files.map((item)=> {
	proc(item);
});

(function output() {
	if(option == "cspace") {
		console.log(includes(files));

		console.log(new named_code().header());
		console.log(new data_structure().header());

		gTranslators.map((item)=>{
			var out = item.generate(gTranslators, "nc");
			if(out) {
				console.log(out);
			}
		});

		gTranslators.map((item)=>{
			var out = item.generate(gTranslators, "data");
			if(out) {
				console.log(out);
			}		
		});
	}

	if(option == "jspace") {
		gTranslators.map((item)=>{
			var out = item.generate(gTranslators, "js");
			if(out) {
				console.log(out);
			}		
		});
	}
})();

function includes(files) {
	var result = "";
	files.map((item)=> {
		result += util.format("#include \"%s\"\n", path.basename(item));
	});
	return result;
}

function readFile(path) {
	fs.accessSync(path, fs.F_OK);
	return fs.readFileSync(path, 'utf8');
}

function proc(path) {
	//console.log("processing...", path);
	var content = readFile(path);

	var ts = new trans_section();
	var lines = content.split("\r\n");

	for(var i=0; i<lines.length; i++) {
		var line = lines[i];
		var translator = ts.feed(line);

		if(translator != undefined) {
			addTranslator(translator)
		}
	}
}

function addTranslator(trans) {
	if(trans.type != "nc") {
		gTranslators.push(trans);
		return;
	}

	var added = false;
	gTranslators.map((item)=> {
		if(item.type != "nc") {
			return;
		}

		if(item.codeName != trans.codeName) {
			return;
		}
		
		added = true;
		item.applies = item.applies.concat(trans.applies);
		item.codes = item.codes.concat(trans.codes);
	});

	if(!added) {
		gTranslators.push(trans);
	}
}