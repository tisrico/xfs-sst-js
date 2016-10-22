const trans_section = require('./trans_section.js').trans_section;
const data_structure = require('./data_structure.js').data_structure;
const named_code = require('./named_code.js').named_code;

const fs = require('fs');
const path = require('path');
const util = require('util');

var args = process.argv.slice(2);
var gSections = [];

args.map((item)=> {
	proc(item);
});

(function output() {
	console.log(includes(args));

	console.log(new named_code().header());
	console.log(new data_structure().header());

	gSections.map((item)=>{
		var out = item.generate(gSections, "nc");
		if(out != undefined) {
			console.log(out);
		}
	});

	gSections.map((item)=>{
		var out = item.generate(gSections, "data");
		if(out != undefined) {
			console.log(out);
		}		
	});

})();

function includes(args) {
	var result = "";
	args.map((item)=> {
		result += util.format("#include \"%s\"\n", path.basename(item));
	});
	return result;
}

function read_file(path) {
	fs.accessSync(path, fs.F_OK);
	return fs.readFileSync(path, 'utf8');
}

function proc(path) {
	//console.log("processing...", path);
	var content = read_file(path);

	var ts = new trans_section();
	var lines = content.split("\r\n");

	for(var i=0; i<lines.length; i++) {
		var line = lines[i];
		var fs = ts.feed(line);

		if(fs != undefined) {
			//console.log(fs);
			gSections.push(fs);
		}
	}
}