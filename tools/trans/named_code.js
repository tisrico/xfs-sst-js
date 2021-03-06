const util = require('util');

exports.named_code = class {
	constructor(ts) {
		if(undefined == ts) {
			return;
		}

		this.type = ts.markup.name;
		this.applies = [];	// 1
		this.codes = [];  // 2
		this.codeName = ts.markup.codeName;
		this.bitwise = ts.markup.bitwise;

		// 1
		for (var i =0; i< ts.markup.applies.length; i++) {
			var apply = ts.markup.applies[i];
			var info = apply.split('.');
			this.applies.push(info);
		}

		// 2
		for (var i =0; i< ts.lines.length; i++) {
			var line = ts.lines[i];
			var reg = /(^#define\s+)([A-Z0-9_-]+)/g
			var code= reg.exec(line);

			if(null != code) {
				this.codes.push(code[2]);
			}
		}
	}

	generate(gs, run) {
		if(run != "nc") {
			return ;
		}

		var result = "";
		result += ("//##############################################################################\n");
		result += util.format("// Get%sName Get%sId \n", this.codeName, this.codeName);
		result += ("//##############################################################################\n");
		result += util.format("#define List%s(expr) \\\n", this.codeName);
		this.codes.map((code)=>{
			result += util.format("\texpr(%s) \\\n", code);
		});

		result += util.format("\n%s(%s);\n", 
				this.bitwise?"DBWNICODE":"DNICODE",	this.codeName)

		return result;
	}

	header() {
		var result = "#include \"nc.h\"\n";
		return result;
	}	
};
