const named_code = require('./named_code.js').named_code;

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
			var markup = JSON.parse(line.slice(spos, epos));
			console.log(markup);

			if(!this.started) {
				this.started = true;
				this.markup =  markup;
				this.lines = [];
			}
			else {
				console.assert(markup.name == "end");
				this.started = false;	
				//console.log(this);
				if(this.markup.name == "nc") {
					return new named_code(this);
				}
				return ;
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
