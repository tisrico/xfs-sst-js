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
	ulock: function() {
     	return this.___call({title:"ulock",
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

