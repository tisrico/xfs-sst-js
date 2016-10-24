const util = require('util');
function logif(a, ...args) {
	if(a) {
		console.log(...args);
	}
}

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
	this.fixedArray = false;
	this.arrayLength = 0;

	var reg = /(.*)(\[(.*)\])/;
	if(reg.test(f2)) {
		var parts = reg.exec(f2);

		this.fixedArray = true;
		this.csName = parts[1];
		this.arrayLength = parts[3];
	}

	// char[] should not be treated as array
	if(this.type == "CHAR" && this.fixedArray) {
		this.fixedArray = false;
	}

	var spos = f3.indexOf("{");
	var epos = f3.lastIndexOf("}")+1;
	this.extra = eval(util.format("Object(%s)", f3.slice(spos, epos)));
	this.jsName = this.csName.replace(/^[a-z]*/, "").uncapitalize();

	this.take_addr = false;
	if(this.extra.hasOwnProperty('take_addr')) {
		this. take_addr = this.extra.take_addr;
	}

	this.ntArray = false;
	if(this.extra.hasOwnProperty('ntArray')) {
		this.ntArray = this.extra.ntArray;
	}

	this.scope = "";
	if(this.extra.hasOwnProperty('scope')) {
		this.scope = this.extra.scope;
	}

	this.codeName = "";
	if(this.extra.hasOwnProperty('codeName')) {
		this.codeName = this.extra.codeName;
	}

	this.namedArray = false;
	if(this.extra.hasOwnProperty('namedArray')) {
		this.namedArray = this.extra.namedArray;
	}

	this.namedArrayIndex = "";
	if(this.extra.hasOwnProperty('namedArrayIndex')) {
		this.namedArrayIndex = this.extra.namedArrayIndex;
	}

	this.valueAtPointer = false;
	if(this.extra.hasOwnProperty('valueAtPointer')) {
		this.valueAtPointer = this.extra.valueAtPointer;
	}

	this.ntStringList = false;
	if(this.extra.hasOwnProperty('ntStringList')) {
		this.ntStringList = this.extra.ntStringList;
	}

	this.kvGroups = false;
	if(this.extra.hasOwnProperty('kvGroups')) {
		this.kvGroups = this.extra.kvGroups;
	}

}

function find_ds(gs, type) {
	var ds = undefined;

	gs.map((item)=>{
		if(item.type != "data" || ds) {
			return;
		}

		if(("LP"+(item.struct)) == type){
			ds = item;
		} 
		else if((item.struct) == type){
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

		if(field.codeName == item.codeName) {
			nc = item;
		}

		if(nc!=undefined) {
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

function find_nci(gs, applies) {
	var nc = undefined;
	gs.map((item)=>{
		if(item.type != "nc" || nc) {
			return;
		}

		item.applies.map((it)=>{
			//console.log(it);
			if(applies == it.join(".")) {
				nc = item;
				return;
			}
		});

	});

	return nc;
}


exports.data_structure = class {
	constructor(ts) {
		if(undefined == ts) {
			return;
		}

		this.type = ts.markup.name;
		this.struct = ts.markup.type;
		this.name = ts.markup.codeName;
		//this.markup = ts.markup;
		this.fields = [];	// 1

		this.leading = 0;
		if(ts.markup.hasOwnProperty('leading')) {
			this.leading = ts.markup.leading;
		}

		this.directCopy = false;
		if(ts.markup.hasOwnProperty('directCopy')) {
			this.directCopy = ts.markup.directCopy;
		}

		this.output = false;
		if(ts.markup.hasOwnProperty('output')) {
			this.output = ts.markup.output;
		}

		this.input = false;
		if(ts.markup.hasOwnProperty('input')) {
			this.input = ts.markup.input;
		}

		this.command = "";
		if(ts.markup.hasOwnProperty('command')) {
			this.command = ts.markup.command;
		}

		if(this.directCopy) {
			this.fields = ts.lines;
			return;
		}

		// 1
		for (var i =0; i< ts.lines.length; i++) {
			var line = ts.lines[i];
			if(!/xfs-sst-js/.test(line)) {
				continue;
			}

			var reg = /(\s*)([^\s]*)([\s\*]*)([^\s;]*)(.*)(xfs-sst-js.*)/g
			var parts = reg.exec(line);

			if(null != parts) {
				this.fields.push(new data_field(parts[2], parts[4], parts[6]));
			}
		}
	}

	generate(gs, run) {
		if("js" == run) {
			return this.jspace();
		}

		if(!/data.*/.test(run)) {
			return ;
		}

		if(run == "data.header") {
			return header();
		}

		var result = this.toJson(gs);
		result += this.fromJson(gs);
		//result += this.

		return result;
	}

	jspace() {
		return "";
	}

	header() {
		var result = "";
		result += "#include \"json.hpp\"\n";
		result += "using json = nlohmann::json;\n\n";
		result += ("//##############################################################################\n");
		result += ("//##############################################################################\n");
		result += ("template <typename T>\n");
		result += ("T* XSJTranslate(const json& j, XSJAllocator* a);\n\n");

		result += ("template <typename T>\n");
		result += ("json XSJTranslate(const T* p);\n\n");

		return result;
	}

	toJson(gs) {
		
		if(!this.output) {
			return "";
		}

		var result = "";
		result += "//##############################################################################\n";
		if(this.command) {
			result += util.format("// %s, in:%s, out:%s\n", this.command, this.input, this.output);
		}
		result += "//##############################################################################\n";
		result += "template <>\n";
		result += util.format("json XSJTranslate(const %s* p) {\n", this.struct);
		result += "\tjson j;\n";
		result += "\tif(!p) return j;\n\n";

		if(this.directCopy) {

			this.fields.map((f)=>{
				result += f + "\n";
			});
			result += "\n\treturn j;\n}\n";
			return result;
		}

		// fields
		this.fields.map((f)=>{

			var prefix ="";
			var condition ="";

			if(f.take_addr) {
				prefix = "&";
			} else {
				if(f.valueAtPointer) {
					prefix = "*";
					condition = util.format("\tif(p->%s%s)\n\t", f.scope, f.csName);
				}
			}

			/*if(f.csName.substring(0,2) == "lp") {
				condition = util.format("\tif(p->%s%s)\n\t", f.scope, f.csName);	
			}*/


			if(!f.fixedArray && !f.ntArray && !f.namedArray && !f.ntStringList) {
				// search if it is a known data type
				var pds = find_ds(gs, f.type);
				if(pds) {
					//j[jsName]=XSJTranslate<f.type>(p->csName);
					result += util.format("%s\tj[\"%s\"] = XSJTranslate<%s>(%s(p->%s%s));\n",
						condition, f.jsName.uncapitalize(pds.leading), 
						f.take_addr?f.type:f.type.slice(2), 
						prefix, f.scope, f.csName);
					return;
				}

				// search if it is a known named code
				var pnc = find_nc(gs, this, f);
				if(pnc) {
					//j[jsName]=GetXXXName(p->csName);
					result += util.format('%s\tj[\"%s\"] = Get%sName(%s(p->%s%s));\n',
						condition, f.jsName, pnc.codeName, 
						prefix,
						f.scope, f.csName);
				}
				else {
					result += util.format('%s\tj[\"%s\"] = %s(p->%s%s);\n',
						condition, f.jsName, prefix, f.scope, f.csName);
				}

				return;
			}

			if(f.fixedArray || f.namedArray) {
				var prefix = "XSJ_ListArray";
				var mainConverter = "NULL";
				var indexConverter = "NULL";

				if(!f.fixedArray) {
					XSJ_ListArray
				}

				if(f.valueAtPointer) {
					prefix +=  "Value";
				}

				var pds = find_ds(gs, f.type);
				if(pds) {
					mainConverter = util.format("XSJTranslate<%s>", pds.struct);
				}

				var pnc = find_nc(gs, this, f);
				if(pnc) {
					mainConverter = util.format("Get%sName", pnc.codeName);
				}

				if(f.namedArray) {
					var pnci = find_nci(gs, f.namedArrayIndex);
					if(pnci) {
						indexConverter = util.format("Get%sName", pnci.codeName);
					}
				}

				var length = f.arrayLength;

				result += util.format('%s\tj[\"%s\"] = %s(p->%s%s, %s, %s, %s);\n',
					condition, f.jsName, prefix, f.scope, f.csName, 
					mainConverter, indexConverter, length);

				return;
			}

			if(f.ntArray) {
				var prefix = "XSJ_ListNullTerminatedPointers";
				var converter = "NULL";

				if(f.valueAtPointer) {
					prefix += "Value";
				}

				var pds = find_ds(gs, f.type);
				if(pds) {
					converter = util.format("XSJTranslate<%s>", pds.struct);
				}

				result += util.format('%s\tj[\"%s\"] = %s(p->%s%s, %s);\n',
					condition, f.jsName, prefix, f.scope, f.csName, converter);

				return;
			}

			if(f.ntStringList) {

				result += util.format('%s\tj[\"%s\"] = XSJ_List2Strings(p->%s%s);\n',
					condition, f.jsName, f.scope, f.csName);
				return;
			}
			
			console.warn(this);
			console.warn("field not supported", f);

		});

		result += "\n\treturn j;\n}\n";
		return result;
	}

	fromJson(gs) {
		var result = "";
		if(!this.input) {
			return result;
		}

		result += "//##############################################################################\n";
		if(this.command) {
			result += util.format("// %s, in:%s, out:%s\n", this.command, this.input, this.output);
		}
		result += "//##############################################################################\n";
		result += "template <>\n";
		result += util.format("%s* XSJTranslate(const json& j, XSJAllocator* a) {\n", this.struct);
		result += "\tXSJAllocator allocator;\n";
		result += "\tif(nullptr==a){\n\t\ta = &allocator;\n\t}\n";
		result += util.format("\tauto p = (%s*)a->Get(sizeof(%s));\n\n", this.struct, this.struct);

		//console.log(this);

		// fields
		this.fields.map((f)=>{
			//console.log(f);

			if(!f.fixedArray && !f.ntArray && !f.namedArray && !f.kvGroups) {

				// search if it is a known data structure nested
				var pds = find_ds(gs, f.type);
				if(pds) {
					// convert j[jsName] => f.Type instance
					result += util.format("\tp->%s =  XSJTranslate(j[\"%s\"], nullptr);",
						f.csName, f.jsName);
					return;
				}

				// search if it is a known named code
				var pnc = find_nc(gs, this, f);
				if(pnc) {

					// p->csName = GetXXXId(j[jsname]);
					result += util.format("\tp->%s = (%s)Get%sId(j[\"%s\"]);\n", 
						f.csName, f.type, pnc.codeName, f.jsName);			
				}
				else {

					// p->csName = (TYPE)j[jsname];
					var isPointer = (f.type.substring(0, 2) == "LP");
					if(!isPointer) {
						result += util.format("\tp->%s = (%s)j[\"%s\"];\n", 
							f.csName, f.type, f.jsName);
					}
					else {
						// LPSTR
						if(f.type == "LPSTR") {
							result += util.format("\tp->%s = a->Get(j[\"%s\"].get<std::string>());\n", 
								f.csName, f.jsName);
						}
						else {
							console.warn("unknown pointer type", this);
						}
					}
				}

				return;
			}

			if(f.kvGroups) {
				console.assert(this.struct == "WFSPTRPRINTFORM" && f.csName == "lpszFields", this);
				result += util.format("\tp->%s = XSJDecodePtrFields(j[\"%s\"], a);\n", 
					f.csName, f.jsName);
				return;
			}

			console.warn(this);
			console.warn("field not supported", f);
		});

		result += util.format("\n\treturn a->Get<%s>();\n}\n", this.struct);
		return result;
	}
};
