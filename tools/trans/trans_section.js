const named_code = require('./named_code.js').named_code;
const data_structure = require('./data_structure.js').data_structure;

const util = require('util');

exports.trans_section = class {
	constructor(ts) {
		this.lines = ts;
		this.started = false;
		this.markup = null;
	}

	feed(line) {

		// parse if it's markup line
		if( -1 != line.indexOf("xfs-sst-js")) {
			var spos = line.indexOf("{");
			var epos = line.lastIndexOf("}")+1;
			var markup = eval(util.format("Object(%s)", line.slice(spos, epos)));
			//console.log(markup);

			if(!this.started) {
				this.started = true;
				this.markup =  markup;
				this.lines = [];
			}
			else {
				if(markup.name != "end") {
					this.lines.push(line);
					return;;
				}

				this.started = false;	
				//console.log(this);
				if(this.markup.name == "nc") {
					return new named_code(this);
				}
				else if(this.markup.name == "data" || this.markup.name=="duplica") {
					return new data_structure(this);
				}
				return;
			}
		}
		else {
			if(this.started) {
				this.lines.push(line);
			}

			return;
		}
	}	
};
