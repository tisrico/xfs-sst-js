const fs = require('fs');
const trans_section = require('./trans_section.js').trans_section;

var args = process.argv.slice(2);
var gSections = [];

args.map((item)=> {
	proc(item);
});

(function output() {
	
	gSections.map((item)=>{
		var out = item.generate(gSections, "nc");
		if(out != undefined) {
			//console.log(out);
		}
	});
	
	console.log("//##############################################################################");
	console.log("//##############################################################################");
	console.log("template <typename T>");
	console.log("T* XSJTranslate(const json& j);");

	console.log("template <typename T>");
	console.log("json XSJTranslate(const T* p);");
	console.log("");

	gSections.map((item)=>{
		var out = item.generate(gSections, "data");
		if(out != undefined) {
			console.log(out);
		}		
	});

})();

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