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

String.prototype.capitalize = function(pos) {
	pos=pos?pos:1;

	var result = "";
	for(var i=0; i<pos; i++) {
		result += this.charAt(i).toUpperCase();
	}
	return  result + this.slice(pos);
}

function parseCommand(command) {
	var regx = /WFS_([A-Z]+)_([A-Z]+)(.*)/g;
	var results = regx.exec(command);

	this.type = results[1].toLowerCase();
	this.class = results[2].toLowerCase();
	this.name = "";

	var rest = results[3];

	regx = /_([A-Z]+)/g;
	var match = regx.exec(rest);
	while(match != null) {
		this.name += match[1].toLowerCase().capitalize();
		match = regx.exec(rest);
	}

	this.name = this.name.uncapitalize();
	this.tag = command;
}

function xfsDevice(c) {
	this.deviceClass = c;

	this.solicited = {};
	this.unsolicite = [];

	this.add = function(item) {
		var p = new parseCommand(item.command);
		if(p.type == 'inf' || p.type == 'cmd') {
			var sol;

			if(this.solicited.hasOwnProperty(item.command)) {
				sol = this.solicited[item.command];
			}
			else {
				sol = new xfsSolicited(p);
				this.solicited[item.command] = sol;
			}

			sol.attach(item);
		}
		else {
			//this.unsolicite.push(new xfsEntry(item, p))	
		}
	}

	this.build = function() {
		var processed = [];
		var result = "";
		result += util.format("function Xfs%s() {\n}\nXfs%s.prototype = {\n", 
			this.deviceClass.capitalize(), this.deviceClass.capitalize());

		for(var x in this.solicited) {
			result += this.solicited[x].build(processed);
		}

		processed = [];
		this.unsolicite.map((item)=>{
			result += item.build(processed);
		});

		result += "};\n\n"
		result += util.format("exports.Xfs%s = Xfs%s;\n", 
			this.deviceClass.capitalize(), this.deviceClass.capitalize());
		result += "\n\n";
		return result;
	}
}

function xfsSolicited(p) {
	this.type = p.type;
	this.name = p.name;
	this.tag = p.tag;
	this.ds_in = null;
	this.ds_out = null;

	this.attach = function (item) {
		if(item.output) {
			this.ds_out = item;
		}

		if(item.input) {
			this.ds_in = item;
		}
	}

	this.build = function (processed) {
		if(p.type == 'inf' || p.type == 'cmd') {
			return this.buildSolicted(processed);
		}
		else {
			return this.buildUnsolicited(processed);
		}
	}

	this.buildSolicted = function(processed) {
		var params = this.buildParams();
		var body = this.buildCallBody();

		var result = util.format("\t%s: function(%s){\n", this.name, params);
		result += body;	
		result += "\t},\n\n";
		return result;
	}

	this.buildParams = function() {
		var result = "";
		if(!this.ds_in) {
			return "";
		}

		var names = [];
		this.ds_in.fields.map((f) =>{
			names.push(f.jsName);
		});

		return names.join(", ");
	}

	this.buildCallData = function () {
		var result = "";
		if(!this.ds_in) {
			return "{}";
		}

		result = "{\n";
		var pairs = [];
		this.ds_in.fields.map((f) =>{
			pairs.push(util.format("\t\t\t%s: %s||%s", f.jsName, f.jsName, 
				JSON.stringify(f.defaultValue)));
		});

		result += pairs.join(",\n") + "\n\t\t}";
		return result;
	}

	this.buildCallBody = function() {
		var result = "";
		var cd = this.buildCallData();;
		if(this.type == "inf") {
			result += util.format("\t\treturn this._query('%s', %s);\n", 
				this.tag, cd);
		}
		else {
			result += util.format("\t\treturn this._execute('%s', %s);\n", 
				this.tag, cd);
		}
		return result;
	}

	this.buildUnsolicited = function (processed) {
		return "";
	}
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
	if((this.type == "CHAR" || this.type == "char") && this.fixedArray) {
		this.fixedArray = false;
	}

	var spos = f3.indexOf("{");
	var epos = f3.lastIndexOf("}")+1;
	this.extra = eval(util.format("Object(%s)", f3.slice(spos, epos)));
	this.jsName = this.csName.replace(/^[a-z]*/, "").uncapitalize();

	this.fixedArrayNNT = false;
	if(this.extra.hasOwnProperty('fixedArrayNNT')) {
		this.fixedArrayNNT = this.extra.fixedArrayNNT;
	}

	this.take_addr = false;
	if(this.extra.hasOwnProperty('take_addr')) {
		this.take_addr = this.extra.take_addr;
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

	this.pointer2FixedArray = false;
	if(this.extra.hasOwnProperty('pointer2FixedArray')) {
		this.pointer2FixedArray = this.extra.pointer2FixedArray;
	}

	this.pointer2FixedArrayLength = false;
	if(this.extra.hasOwnProperty('pointer2FixedArrayLength')) {
		this.pointer2FixedArrayLength = this.extra.pointer2FixedArrayLength;
	}	

	this.fixedArrayPointers = false;
	if(this.extra.hasOwnProperty('fixedArrayPointers')) {
		this.fixedArrayPointers = this.extra.fixedArrayPointers;
	}

	this.fixedArrayPointersLength = false;
	if(this.extra.hasOwnProperty('fixedArrayPointersLength')) {
		this.fixedArrayPointersLength = this.extra.fixedArrayPointersLength;
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

	this.defaultValue="";
	if(this.extra.hasOwnProperty('defaultValue')) {
		this.defaultValue = this.extra.defaultValue;
	}

	this.seq = 0;
	if(this.extra.hasOwnProperty('seq')) {
		this.seq = this.extra.seq;
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

		this.ntArray = false;
		if(ts.markup.hasOwnProperty('ntArray')) {
			this.ntArray = ts.markup.ntArray;	
		}

		this.nestedStruct = false;
		if(ts.markup.hasOwnProperty('nestedStruct')) {
			this.nestedStruct = ts.markup.nestedStruct;	
		}

		this.nestedType = "";
		if(ts.markup.hasOwnProperty('nestedType')) {
			this.nestedType = ts.markup.nestedType;	
		}

		this.nestedCast = "";
		if(ts.markup.hasOwnProperty('nestedCast')) {
			this.nestedCast = ts.markup.nestedCast;	
		}

		this.sortFields = false;
		if(ts.markup.hasOwnProperty('sortFields')) {
			this.sortFields = ts.markup.sortFields;	
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

		if(this.sortFields) {
			this.fields.sort((a, b)=> {
				return a.seq - b.seq;
			});;
		}
	}

	generate(gs, run, records) {
		if("js" == run) {
			return this.jspace();
		}

		if(!/data.*/.test(run)) {
			return ;
		}

		if(run == "data.header") {
			return header();
		}

		let r1 = "";
		let r2 = "";

		if(!records.output.hasOwnProperty(this.struct)) {
			r1 = this.toJson(gs);
		}

		if(!records.input.hasOwnProperty(this.struct)) {
			r2 = this.fromJson(gs);
		}

		if(r1) {
			records.output[this.struct] = true;
		}

		if(r2) {
			records.input[this.struct] = true;
		}

		return r1 + r2;
	}

	jspace(gs) {

		var result = "\n";

		var devices = {};
		gs.map((item)=>{
			if(item.type != "data" || item.command == "") {
				return;
			}

			var pc = new parseCommand(item.command);
			var xd;

			if(devices.hasOwnProperty(pc.class)) {
				xd = devices[pc.class];
			}
			else {
				xd = new xfsDevice(pc.class);
				devices[pc.class] = xd;
			}

			xd.add(item);

		});
		
		for(var property in devices) {
			var device = devices[property];
			result += device.build();
		}
		return result;
	}

	makeTranslatorTable(gs) {
		var result = "";
		result += "inline Translator* GetTranslators(int& size) {\n";
		result += "\tstatic Translator transators[] = {\n";

		gs.map((item)=> {
			if(item.type != "data") {
				return;
			}

			if(item.command == "") {
				return;
			}

			console.assert(item.output || item.input, "wrong data time", item);

			var fpToJS = "nullptr";
			var fpToXFS = "nullptr";

			if(item.output) {
				if(item.ntArray) {
					fpToJS = util.format("([](const LPVOID p){ return XSJ_ListNullTerminatedPointers((const %s**)p, XSJTranslate<%s>); })", item.struct, item.struct);
				}
				else {
					if(item.nestedStruct) {
						if(item.nestedCast) {
							fpToJS = util.format("([](const LPVOID p){ %s ns = {(%s)*(%s)p}; return XSJTranslate(&ns); })", item.struct, item.nestedType, item.nestedCast);
						}
						else {
							fpToJS = util.format("([](const LPVOID p){ %s ns = {(%s)p}; return XSJTranslate(&ns); })", item.struct, item.nestedType);
						}
					}
					else {
						fpToJS = util.format("([](const LPVOID p){ return XSJTranslate((LP%s)p); })", item.struct);
					}
				}
			}

			if(item.input) {
				fpToXFS = util.format("([](const json& j){ return (LPVOID)XSJTranslate<%s>(j, nullptr); })", item.struct);
			}

			result += util.format("\t\t{\n\t\t\t\"%s\", \n\t\t\t\"%s\", \n\t\t\t%s, \n\t\t\t%s\n\t\t},\n", 
				item.command, item.name, fpToXFS, fpToJS);

		});

		result += "\t};\n";
		result += "\tsize = sizeof(transators)/sizeof(Translator);\n";
		result += "\treturn transators;\n}\n\n";
		return result;
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
		result += util.format("inline json XSJTranslate(const %s* p) {\n", this.struct);
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


			if(f.fixedArrayNNT) {
				result += util.format('%s\tj[\"%s\"] = std::string(p->%s, p->%s + %d);\n',
					condition, f.jsName, f.csName, f.csName, f.arrayLength);
				return;
			}

			if(f.pointer2FixedArray) {
				f.fixedArray = true;
				f.arrayLength = f.pointer2FixedArrayLength;
			}			

			if(f.fixedArrayPointers) {
				f.fixedArray = true;
				f.arrayLength = f.fixedArrayPointersLength;
			}

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

					// special types that json can't directly accept
					if(f.type == "LPSTR" || f.type == "LPWSTR" || f.type == "LPBYTE") {
						prefix = "XSJ_Stringify";
					}
					else if(f.type == "SYSTEMTIME") {
						prefix = "XSJ_SystemTime2String";
					}

					result += util.format('%s\tj[\"%s\"] = %s(p->%s%s);\n',
						condition, f.jsName, prefix, f.scope, f.csName);
				}

				return;
			}

			if(f.fixedArray || f.namedArray) {
				var prefix = "XSJ_ListArray";
				var mainConverter = "(json(*)(const int))nullptr";
				var indexConverter = "(std::string(*)(const int))nullptr";

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
				var cast = util.format("(const %s **)", f.type.substring(2));

				if(f.valueAtPointer) {
					prefix += "Value";
				}

				var pds = find_ds(gs, f.type);
				if(pds) {
					converter = util.format("XSJTranslate<%s>", pds.struct);
				}

				result += util.format('%s\tj[\"%s\"] = %s(%sp->%s%s, %s);\n',
					condition, f.jsName, prefix, cast, f.scope, f.csName, converter);

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
		result += util.format("inline %s* XSJTranslate(const json& j, XSJAllocator* a) {\n", this.struct);
		result += "\tXSJAllocator allocator;\n";
		result += "\tif(nullptr==a){\n\t\ta = &allocator;\n\t}\n";
		result += util.format("\tauto p = a->Get<%s>();\n\n", this.struct);

		//console.log(this);

		// fields
		this.fields.map((f)=>{
			//console.log(f);
			if(this.directCopy) {
				result += f + "\n";
				return;
			}

			var condition = util.format('\tif (j.find("%s") != j.end() && !j["%s"].is_null())\n\t', f.jsName, f.jsName);

			if(f.type == "__CHARRAY" && f.fixedArray && f.arrayLength) {
				result += util.format("%s\tstd::strncpy(p->%s, j[\"%s\"].get<std::string>().c_str(), %s);\n\n", 
					condition, f.csName, f.jsName, f.arrayLength);
				return;
			}

			if(f.pointer2FixedArray) {
				condition += util.format('\tif(j["%s"].is_array())\n', f.jsName);
				result += util.format("%s\t\t\tp->%s = a->AllocateArray<%s>(j[\"%s\"], %s);\n\n", 
					condition, f.csName, f.type.slice(2), f.jsName, f.pointer2FixedArrayLength);
				return;
			}

			if(f.fixedArrayPointers) {
				condition += util.format('\tif(j["%s"].is_array())\n', f.jsName);
				result += util.format("%s\t\t\tp->%s = a->AllocateArrayPointers<%s>(j[\"%s\"], %s);\n\n", 
					condition, f.csName, f.type.slice(2), f.jsName, f.fixedArrayPointersLength);
				return;
			}

			if(f.ntArray) {
				condition += util.format('\tif(j["%s"].is_array())\n', f.jsName);
				result += util.format("%s\t\t\tp->%s = a->AllocateArrayPointersNT<%s>(j[\"%s\"]);\n\n", 
					condition, f.csName, f.type.slice(2), f.jsName);
				return;
			}

			if(!f.fixedArray && !f.ntArray && !f.namedArray && !f.kvGroups) {

				// search if it is a known data structure nested
				var pds = find_ds(gs, f.type);
				if(pds) {
					// convert j[jsName] => f.Type instance
					result += util.format("%s\tp->%s =  XSJTranslate<%s>(j[\"%s\"], a);\n\n",
						condition, f.csName, pds.struct, f.jsName);
					return;
				}

				// search if it is a known named code
				var pnc = find_nc(gs, this, f);
				if(pnc) {

					// p->csName = GetXXXId(j[jsname]);
					result += util.format("%s\tp->%s = (%s)Get%sId(j[\"%s\"]);\n\n", 
						condition, f.csName, f.type, pnc.codeName, f.jsName);			
				}
				else {
					// p->csName = (TYPE)j[jsname];
					var isPointer = (f.type.substring(0, 2) == "LP");
					if(!isPointer) {
						result += util.format("%s\tp->%s = (%s)j[\"%s\"];\n\n", 
							condition, f.csName, f.type, f.jsName);
					}
					else {
						// LPSTR
						if(f.type == "LPSTR") {
							result += util.format("%s\tp->%s = a->Get(j[\"%s\"].get<std::string>());\n\n", 
								condition, f.csName, f.jsName);
						}
						else if(f.type == "LPBYTE") {
							result += util.format("%s\tp->%s = (%s)a->Get(j[\"%s\"].get<std::string>());\n\n", 
								condition, f.csName, f.type, f.jsName);
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
				result += util.format("%s\tp->%s = XSJDecodePtrFields(j[\"%s\"], a);\n\n", 
					condition, f.csName, f.jsName);
				return;
			}

			console.warn(this);
			console.warn("field not supported", f);
		});

		result += util.format("\n\treturn (%s*)a->Get();\n}\n", this.struct);
		return result;
	}
};
