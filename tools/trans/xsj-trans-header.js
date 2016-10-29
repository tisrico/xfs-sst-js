var __XfsDevice = require('bindings')('xsj').XfsDevice;
var __XfsMgr = require('bindings')('xsj').XfsMgr;

const mixin = require('mixin');

function inhertits(target, source) {
  for (var k in source.prototype) {
    target.prototype[k] = source.prototype[k];
  }
  return target;
}

function _XfsMgr() {
}

_XfsMgr.prototype = {
	___call: function (cd) {
		if(typeof(cd.data) == "string") {
			return this.__call(cd.title, cd.data);
		}
		else {
			return this.__call(cd.title, JSON.stringify(cd.data));
		}
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
		return result = this.___call({title:"start", 
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

		return this.___call({title:"open", data:{
			logicalName: logicalName,
			versionsRequired: parseInt(version),
			appHandle: parseInt(appHandle),
			appId: appId?appId:"no_used", 
			traceLevel: traceLevel,
			timeOut: timeOut
		}});
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
	preprocessor: function(title, message) {
		if(title=="open") {
			var msg = JSON.parse(message.substring(5));
			this.services[msg.service] = msg.class;
			return;
		}

		if(title=="open.complete") {
			var msg = JSON.parse(message.substring(5));
			msg.class = this.services[msg.service];
			message= "data:" + JSON.stringify(msg);
			return;
		}
	},
	services: {}
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
			requestID:requestID
		});
	},
	close: function() {
     	return this.___call({title:"close",
			data:{}
		});		
	},
	register: function(eventClass) {
     	return this.___call({title:"register",
			eventClass:eventClass
		});		
	},
	deregister: function(eventClass) {
     	return this.___call({title:"deregister",
			eventClass:eventClass
		});		
	},
};

exports.XfsMgr = inhertits(__XfsMgr, _XfsMgr);
var XfsDevice = inhertits(__XfsDevice, _XfsDevice);
