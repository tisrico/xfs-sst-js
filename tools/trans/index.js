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
		console.log(beginCSpace());

		console.log(includes(files));
		console.log(new named_code().header());
		console.log(new data_structure().header());

		// named codes
		gTranslators.map((item)=>{
			var out = item.generate(gTranslators, "nc");
			if(out) {
				console.log(out);
			}
		});

		// data structure translators
		let records = {input:{}, output:{}};
		gTranslators.map((item)=>{
			var out = item.generate(gTranslators, "data", records);
			if(out) {
				console.log(out);
			}		
		});

		console.log(new data_structure().makeTranslatorTable(gTranslators));
		console.log(endCSpace());
		return;
	}

	if(option == "jspace") {
		console.log(readFile(__dirname + "/xsj-trans-header.js"));
		console.log(new data_structure().jspace(gTranslators));
		return;
	}
})();

function beginCSpace() {
	return "#ifndef __xsj_translate__h\n#define __xsj_translate__h\n";
}

function endCSpace() {
	return "#endif";
}

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

function addDSTranslator(trans) {
	if(trans.type == "data") {
		gTranslators.push(trans);
		return;
	}

	// assert trans.type == "duplica"
	for(let t of gTranslators) {
		if(t.type == "data" && t.struct == trans.struct && t.name == trans.name) {

			t.fields.map((f)=>{
				trans.fields.push(f);
			});

			trans.type = "data";
			gTranslators.push(trans);
			break;
		}
	}
}

function addTranslator(trans) {
	if(trans.type != "nc") {
		addDSTranslator(trans);
		return;
	}

	// merge with existing nc with same codeName
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