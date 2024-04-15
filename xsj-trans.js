var __XfsDevice = require('bindings')('xsj').XfsDevice;
var __XfsMgr = require('bindings')('xsj').XfsMgr;
const util = require('util');

const mixin = require('mixin');

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

function inhertits(target, source) {
  for (var k in source.prototype) {
    target.prototype[k] = source.prototype[k];
  }
  return target;
}

function object_extend(target, source) {
  for (var k in source.prototype) {
    target[k] = source.prototype[k];
  }
  return target;
}

function _XfsMgr() {
}

_XfsMgr.prototype = {
	___call: function (cd) {
		var result;
		if(typeof(cd.data) == "string") {
			result = this.__call(cd.title, cd.data);
		}
		else {
			result = this.__call(cd.title, JSON.stringify(cd.data));
		}
		return JSON.parse(result);
	},
	init: function() {
		return this.___call({title:"initialize",
			data: {}
		});
	},
	uninit: function() {
		return this.___call({title:"uninitialize",
			data: {}
		});
	},
	start: function(lowMajor, lowMinor, highMajor, highMinor) {
		var version = (lowMinor<<24)+(lowMajor<<16)+(highMinor<<8)+highMajor;
		return this.___call({title:"start", 
			data: { versionRequired: version }
		});
	},
	cleanUp: function() {
		return this.___call({title:"cleanUp",
			data: {}
		});
	},
	createAppHandle: function() {
		return this.___call({title:"createAppHandle",
			data: {}
		});
	},
	destroyAppHandle: function(handle) {
		return this.___call({title:"destroyAppHandle",
			data: handle
		});
	},
	open: function(logicalName, lowMajor, lowMinor, highMajor, highMinor, appHandle, appId, traceLevel, timeOut) {
		var version = (lowMinor<<24)+(lowMajor<<16)+(highMinor<<8)+highMajor;
		if(appHandle == undefined || "WFS_DEFAULT_HAPP" == appHandle)  {
			appHandle = 0;
		}

		if(timeOut == undefined)  {
			timeOut = this.timeOut;
		}

		if("WFS_INDEFINITE_WAIT" == timeOut)  {
			timeOut = 0;
		}

		if(traceLevel == undefined)  {
			traceLevel = this.traceLevel;
		}

		if(traceLevel == "") {
			traceLevel = "_no_used";
		}

		var result = this.___call({title:"open", data:{
			logicalName: logicalName,
			versionsRequired: parseInt(version),
			appHandle: parseInt(appHandle),
			appId: appId?appId:"no_used", 
			traceLevel: traceLevel,
			timeOut: timeOut
		}});

		this.services[result.service] = result.class;
		return result;
	},
	getDevObject: function(service) {
		if(!this.services.hasOwnProperty(service)) {
			return undefined;
		}
		var cls = this.services[service];
		switch(cls) {
			case "PTR":
				return new XfsPtr(service);
			default:
				console.error('Unknow device class', cls);
		}
	},
	preProcessor: function(args) {
		if(args[0]=="xsj.open.complete") {
			var msg = JSON.parse(args[1]);
			msg.class = this.services[msg.service];
			args[1] = {data:JSON.stringify(msg), 
						object: makeDeviceObject(msg.class, msg.service)};
			return;
		}
	},
	services: {},
}

function makeDeviceObject(clss, id) {
	clss = clss.toLowerCase().capitalize();
	var code = util.format('object_extend(new XfsDevice(%d), Xfs%s)', id, clss);
	return eval(code);
}

Object.defineProperty(__XfsMgr.prototype, "traceLevel", {
    get: function () {
     	return this.___call({title:"getTraceLevel",
			data: ""
		});
    },
    set: function (level) {
     	return this.___call({title:"setTraceLevel",
			data: level
		});        
    }
});

Object.defineProperty(__XfsMgr.prototype, "timeOut", {
    get: function () {
     	return this.___call({title:"getTimeOut",
			data: ""
		});
    },
    set: function (timeOut) {
     	return this.___call({title:"setTimeOut",
			data: timeOut
		});
    }
});

function _XfsDevice() {
}

_XfsDevice.prototype = {
	___call: function (cd) {
		var result;
		if(typeof(cd.data) == "string") {
			result = this.__call(cd.title, cd.data);
		}
		else {
			result = this.__call(cd.title, JSON.stringify(cd.data));
		}
		result = JSON.parse(result);
		this.lastRequest = null;

		if(result.hasOwnProperty('asyncCall') && result.asyncCall) {
			if(result.hasOwnProperty('requestID')) {
				this.lastRequestID = result.requestID;
				return this;
			}
		}
		return result;
	},
	_query: function(command, data) {
     	return this.___call({title:"query",
			data: {command:command, data:data}
		});
	},
	_execute: function(command, data) {
     	return this.___call({title:"execute",
			data: {command:command, data:data}
		});
	},
	lock: function() {
     	return this.___call({title:"lock",
			data:{}
		});
	},
	unlock: function() {
     	return this.___call({title:"unlock",
			data:{}
		});
	},
	cancelRequest: function(requestID) {
     	return this.___call({title:"cancelRequest",
			data: {requestID:requestID}
		});
	},
	close: function() {
     	return this.___call({title:"close",
			data:{}
		});		
	},
	register: function(eventClass) {
     	return this.___call({title:"register",
			data: {eventClass:eventClass}
		});		
	},
	deregister: function(eventClass) {
     	return this.___call({title:"deregister",
			data: {eventClass:eventClass}
		});		
	},
	sync: function() {
		this.___call({title:"sync",
			data: {}
		});
		return this;
    },
	async: function() {
     	this.___call({title:"async",
			data: {}
		});
		return this;
    },
    isSync: function() {
     	return this.___call({title:"isSync",
			data: {}
		});
    },
    isAsync: function() {
     	return this.___call({title:"isAsync",
			data: {}
		});
    },
    getVersion: function() {
     	return this.___call({title:"getVersion",
			data: {}
		});
    },
    then: function(func) {
     	if(this.lastRequestID != null) {
     		this.requests[this.lastRequestID] = func;
     	}
     	return this;
     },
	preProcessor: function(args) {
		args[1] = JSON.parse(args[1]);

		if(args.length >=2 && typeof(args[1]) == "object" && args[1].hasOwnProperty('requestID')) {
			var requestID = args[1]["requestID"];
			if(this.requests.hasOwnProperty(requestID)) {
				var func = this.requests[requestID];
				func(args[1]);
				delete args[1]["requestID"];
			}
		}
	},     
	requests: {} 
};

Object.defineProperty(__XfsDevice.prototype, "service", {
    get: function () {
     	return this.___call({title:"getService",
			data: ""
		});
    }
});


exports.XfsMgr = inhertits(__XfsMgr, _XfsMgr);
var XfsDevice = inhertits(__XfsDevice, _XfsDevice);



function XfsPtr() {
}
XfsPtr.prototype = {
	status: function(){
		return this._query('WFS_INF_PTR_STATUS', {});
	},

	capabilities: function(){
		return this._query('WFS_INF_PTR_CAPABILITIES', {});
	},

	queryForm: function(formName){
		return this._query('WFS_INF_PTR_QUERY_FORM', {
			formName: formName||null
		});
	},

	queryMedia: function(mediaName){
		return this._query('WFS_INF_PTR_QUERY_MEDIA', {
			mediaName: mediaName||null
		});
	},

	queryField: function(formName, fieldName){
		return this._query('WFS_INF_PTR_QUERY_FIELD', {
			formName: formName||"",
			fieldName: fieldName||null
		});
	},

	printForm: function(formName, mediaName, fields, mediaControl, paperSource, alignment, offsetX, offsetY, resolution){
		return this._execute('WFS_CMD_PTR_PRINT_FORM', {
			formName: formName||"",
			mediaName: mediaName||"",
			fields: fields||{},
			mediaControl: mediaControl||"",
			paperSource: paperSource||"WFS_PTR_PAPERANY",
			alignment: alignment||"WFS_PTR_ALNUSEFORMDEFN",
			offsetX: offsetX||0,
			offsetY: offsetY||0,
			resolution: resolution||"WFS_PTR_RESLOW"
		});
	},

	readForm: function(formName, fieldNames, mediaName, mediaControl){
		return this._execute('WFS_CMD_PTR_READ_FORM', {
			formName: formName||"",
			fieldNames: fieldNames||"",
			mediaName: mediaName||"",
			mediaControl: mediaControl||""
		});
	},

	rawData: function(inputData, size, data){
		return this._execute('WFS_CMD_PTR_RAW_DATA', {
			inputData: inputData||"WFS_PTR_NOINPUTDATA",
			size: size||0,
			data: data||""
		});
	},

	mediaExtents: function(base, unitX, unitY){
		return this._execute('WFS_CMD_PTR_MEDIA_EXTENTS', {
			base: base||"WFS_FRM_INCH",
			unitX: unitX||96,
			unitY: unitY||96
		});
	},

	readImage: function(frontImageType, backImageType, frontImageColorFormat, backImageColorFormat, codelineFormat, imageSource, frontImageFile, backImageFile){
		return this._execute('WFS_CMD_PTR_READ_IMAGE', {
			frontImageType: frontImageType||"",
			backImageType: backImageType||"",
			frontImageColorFormat: frontImageColorFormat||"",
			backImageColorFormat: backImageColorFormat||"",
			codelineFormat: codelineFormat||"",
			imageSource: imageSource||"",
			frontImageFile: frontImageFile||null,
			backImageFile: backImageFile||null
		});
	},

	reset: function(mediaControl, retractBinNumber){
		return this._execute('WFS_CMD_PTR_RESET', {
			mediaControl: mediaControl||"WFS_PTR_CTRLRETRACT",
			retractBinNumber: retractBinNumber||0
		});
	},

	formList: function(){
		return this._query('WFS_INF_PTR_FORM_LIST', {});
	},

	mediaList: function(){
		return this._query('WFS_INF_PTR_MEDIA_LIST', {});
	},

	controlMedia: function(mediaControl){
		return this._execute('WFS_CMD_PTR_CONTROL_MEDIA', {
			mediaControl: mediaControl||"WFS_PTR_CTRLEJECT"
		});
	},

	resetCount: function(binNumber){
		return this._execute('WFS_CMD_PTR_RESET_COUNT', {
			binNumber: binNumber||0
		});
	},

	retractMedia: function(binNumber){
		return this._execute('WFS_CMD_PTR_RETRACT_MEDIA', {
			binNumber: binNumber||1
		});
	},

	dispensePaper: function(paperSource){
		return this._execute('WFS_CMD_PTR_DISPENSE_PAPER', {
			paperSource: paperSource||"WFS_PTR_PAPERANY"
		});
	},

};

exports.XfsPtr = XfsPtr;


function XfsCdm() {
}
XfsCdm.prototype = {
	status: function(){
		return this._query('WFS_INF_CDM_STATUS', {});
	},

	capabilities: function(){
		return this._query('WFS_INF_CDM_CAPABILITIES', {});
	},

	cashUnitInfo: function(){
		return this._query('WFS_INF_CDM_CASH_UNIT_INFO', {});
	},

	setCashUnitInfo: function(tellerID, count, list){
		return this._execute('WFS_CMD_CDM_SET_CASH_UNIT_INFO', {
			tellerID: tellerID||0,
			count: count||"",
			list: list||[]
		});
	},

	startExchange: function(exchangeType, tellerID, cUNumList){
		return this._execute('WFS_CMD_CDM_START_EXCHANGE', {
			exchangeType: exchangeType||"WFS_CDM_CREATE_TELLER",
			tellerID: tellerID||0,
			cUNumList: cUNumList||[]
		});
	},

	endExchange: function(tellerID, count, list){
		return this._execute('WFS_CMD_CDM_END_EXCHANGE', {
			tellerID: tellerID||0,
			count: count||"",
			list: list||[]
		});
	},

	testCashUnits: function(number, retractArea, outputPosition){
		return this._execute('WFS_CMD_CDM_TEST_CASH_UNITS', {
			number: number||0,
			retractArea: retractArea||null,
			outputPosition: outputPosition||"WFS_CDM_POSNULL"
		});
	},

	tellerInfo: function(tellerID, currencyID){
		return this._query('WFS_INF_CDM_TELLER_INFO', {
			tellerID: tellerID||0,
			currencyID: currencyID||null
		});
	},

	currencyExp: function(){
		return this._query('WFS_INF_CDM_CURRENCY_EXP', {});
	},

	mixTypes: function(){
		return this._query('WFS_INF_CDM_MIX_TYPES', {});
	},

	mixTable: function(mixNumber){
		return this._query('WFS_INF_CDM_MIX_TABLE', {
			mixNumber: mixNumber||0
		});
	},

	setMixTable: function(mixNumber, name, rows, cols, mixHeader, mixRows){
		return this._execute('WFS_CMD_CDM_SET_MIX_TABLE', {
			mixNumber: mixNumber||0,
			name: name||null,
			rows: rows||0,
			cols: cols||0,
			mixHeader: mixHeader||[],
			mixRows: mixRows||[]
		});
	},

	dispense: function(tellerID, mixNumber, position, present, denomination){
		return this._execute('WFS_CMD_CDM_DISPENSE', {
			tellerID: tellerID||0,
			mixNumber: mixNumber||0,
			position: position||0,
			present: present||false,
			denomination: denomination||[]
		});
	},

	presentStatus: function(position){
		return this._query('WFS_INF_CDM_PRESENT_STATUS', {
			position: position||"WFS_CDM_POSNULL"
		});
	},

	denominate: function(tellerID, mixNumber, denomination){
		return this._execute('WFS_CMD_CDM_DENOMINATE', {
			tellerID: tellerID||0,
			mixNumber: mixNumber||0,
			denomination: denomination||[]
		});
	},

	count: function(emptyAll, position, physicalPositionName){
		return this._execute('WFS_CMD_CDM_COUNT', {
			emptyAll: emptyAll||true,
			position: position||"WFS_CDM_POSNULL",
			physicalPositionName: physicalPositionName||null
		});
	},

	retract: function(outputPosition, retractArea, index){
		return this._execute('WFS_CMD_CDM_RETRACT', {
			outputPosition: outputPosition||"WFS_CDM_POSNULL",
			retractArea: retractArea||"WFS_CDM_RA_RETRACT",
			index: index||0
		});
	},

	setTellerInfo: function(action, tellerDetails){
		return this._execute('WFS_CMD_CDM_SET_TELLER_INFO', {
			action: action||"WFS_CDM_CREATE_TELLER",
			tellerDetails: tellerDetails||{}
		});
	},

	reset: function(number, retractArea, outputPosition){
		return this._execute('WFS_CMD_CDM_RESET', {
			number: number||0,
			retractArea: retractArea||null,
			outputPosition: outputPosition||"WFS_CDM_POSNULL"
		});
	},

	present: function(position){
		return this._execute('WFS_CMD_CDM_PRESENT', {
			position: position||"WFS_CDM_POSNULL"
		});
	},

	reject: function(){
		return this._execute('WFS_CMD_CDM_REJECT', {

		});
	},

	closeShutter: function(position){
		return this._execute('WFS_CMD_CDM_CLOSE_SHUTTER', {
			position: position||"WFS_CDM_POSNULL"
		});
	},

};

exports.XfsCdm = XfsCdm;


function XfsIdc() {
}
XfsIdc.prototype = {
	status: function(){
		return this._query('WFS_INF_IDC_STATUS', {});
	},

	capabilities: function(){
		return this._query('WFS_INF_IDC_CAPABILITIES', {});
	},

	queryForm: function(formName){
		return this._query('WFS_INF_IDC_QUERY_FORM', {
			formName: formName||null
		});
	},

	writeTrack: function(formName, trackData, writeMethod){
		return this._execute('WFS_CMD_IDC_WRITE_TRACK', {
			formName: formName||null,
			trackData: trackData||null,
			writeMethod: writeMethod||"WFS_IDC_LOCO"
		});
	},

	retainCard: function(){
		return this._execute('WFS_CMD_IDC_RETAIN_CARD', {});
	},

	setkey: function(keyLen, keyValue){
		return this._execute('WFS_CMD_IDC_SETKEY', {
			keyLen: keyLen||0,
			keyValue: keyValue||null
		});
	},

	readRawData: function(readData){
		return this._execute('WFS_CMD_IDC_READ_RAW_DATA', {
			readData: readData||"WFS_IDC_TRACK1"
		});
	},

	chipIo: function(chipProtocol, chipDataLength, chipData){
		return this._execute('WFS_CMD_IDC_CHIP_IO', {
			chipProtocol: chipProtocol||"WFS_IDC_NOTSUPP",
			chipDataLength: chipDataLength||0,
			chipData: chipData||null
		});
	},

	chipPower: function(chipPower){
		return this._execute('WFS_CMD_IDC_CHIP_POWER', {
			chipPower: chipPower||"WFS_IDC_CHIPPOWERCOLD"
		});
	},

	writeRawData: function(dataSource, dataLength, data, writeMethod){
		return this._execute('WFS_CMD_IDC_WRITE_RAW_DATA', {
			dataSource: dataSource||"",
			dataLength: dataLength||"",
			data: data||"",
			writeMethod: writeMethod||""
		});
	},

	parseData: function(formName, cardData){
		return this._execute('WFS_CMD_IDC_PARSE_DATA', {
			formName: formName||null,
			cardData: cardData||{}
		});
	},

	readTrack: function(formName){
		return this._execute('WFS_CMD_IDC_READ_TRACK', {
			formName: formName||null
		});
	},

	formList: function(){
		return this._query('WFS_INF_IDC_FORM_LIST', {});
	},

	ejectCard: function(){
		return this._execute('WFS_CMD_IDC_EJECT_CARD', {

		});
	},

	resetCount: function(){
		return this._execute('WFS_CMD_IDC_RESET_COUNT', {

		});
	},

	reset: function(resetIn){
		return this._execute('WFS_CMD_IDC_RESET', {
			resetIn: resetIn||"WFS_IDC_EJECT"
		});
	},

};

exports.XfsIdc = XfsIdc;



