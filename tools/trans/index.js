const fs = require('fs');
const trans_section = require('./trans_section.js').trans_section;

var args = process.argv.slice(2);

args.map((item)=> {
	proc(item);
});

function read_file(path) {
	// it throws if fails
	fs.accessSync(path, fs.F_OK);
	return fs.readFileSync(path, 'utf8');
}

function proc(path) {
	console.log("processing...", path);

	var content = read_file(path);
	var ts = new trans_section();
	var lines = content.split("\r\n");

	for(var i=0; i<lines.length; i++) {
		var line = lines[i];
		var fs = ts.feed(line);

		if(fs != undefined) {
			//console.log(fs);
			//console.log(fs.generate());
		}
	}
}