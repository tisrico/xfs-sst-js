const util = require('util');

String.prototype.uncapitalize = function(pos) {
	pos=pos?pos:1;

	var result = "";
	for(var i=0; i<pos; i++) {
		result += this.charAt(i).toLowerCase();
	}
    return  result + this.slice(pos);
}

function data_field (f1, f2, f3) {
	this.type = f1;
	
	this.csName = f2;
	this.isArray = false;
	this.arrayLength = 0;

	var reg = /(.*)(\[(.*)\])/;
	if(reg.test(f2)) {
		var parts = reg.exec(f2);

		this.isArray = true;
		this.csName = parts[1];
		this.arrayLength = parts[3];
	}

	var spos = f3.indexOf("{");
	var epos = f3.lastIndexOf("}")+1;
	this.extra = eval(util.format("Object(%s)", f3.slice(spos, epos)));
	this.jsName = this.csName.replace(/^[a-z]*/, "").uncapitalize();
}

function find_ds(gs, type) {
	var ds = undefined;
	gs.map((item)=>{
		if(item.type != "data" || ds) {
			return;
		}

		if(("LP"+item.struct) == type){
			ds = item;
		}
	});

	return ds;
}

function find_nc(gs, ds, field) {
	var nc = undefined;
	gs.map((item)=>{
		if(item.type != "nc" || nc) {
			return;
		}

		item.applies.map((it)=>{
			//console.log(it);
			if([ds.struct, field.csName].join(".") == 
				it.join(".")) {
				nc = item;
				return;
			}
		});

	});

	return nc;
}


exports.data_structure = class {
	constructor(ts) {
		this.type = ts.markup.name;
		this.struct = ts.markup.type;
		this.name = ts.markup.codeName;
		this.markup = ts.markup;
		this.fields = [];	// 1

		// 1
		for (var i =0; i< ts.lines.length; i++) {
			var line = ts.lines[i];
			if(!/xfs-sst-js/.test(line)) {
				continue;
			}

			var reg = /(\s*)([^\s]*)(\s*)([^\s;]*)(.*)(xfs-sst-js.*)/g
			var parts = reg.exec(line);

			if(null != parts) {
				this.fields.push(new data_field(parts[2], parts[4], parts[6]));
			}
		}
	}

	generate(gs, run) {
		if(run != "data") {
			return ;
		}

		var result = this.toJson(gs);
		//result += this.fromJson(gs);

		//console.log(this);
		return result;
	}

	toJson(gs) {
		var result = "";
		result += "//##############################################################################\n";
		result += "//##############################################################################\n";
		result += "template <>\n";
		result += util.format("json XSJTranslate(const LP%s p) {\n", this.struct);
		result += "\tjoson j;\n";

		// fields
		this.fields.map((f)=>{
			if(!f.isArray) {

				// search if it is a known data type
				var pds = find_ds(gs, f.type);
				if(pds) {
					//j[jsName]=XSJTranslate<f.type>(p->csName);
					result += util.format("\tj['%s'] = XSJTranslate<%s>( p->%s );\n",
						f.jsName.uncapitalize(pds.markup.leading), f.type, f.csName);
					return;
				}

				// search if it is a known named code
				var pnc = find_nc(gs, this, f);
				if(pnc) {
					//j[jsName]=GetXXXName(p->csName);
					result += util.format("\tj['%s'] = Get%sName( p->%s );\n",
						f.jsName, pnc.codeName, f.csName);
					return;
				}
				else {
					result += util.format("\tj['%s'] = ( p->%s );\n",
						f.jsName, f.csName);
					return;					
				}
			}
		});

		result += "\treturn j;\n}\n";

		return result;
	}

	fromJson(gs) {
	}
};
