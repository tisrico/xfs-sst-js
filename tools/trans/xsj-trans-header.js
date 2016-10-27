var XfsDevice = require('bindings')('xsj').XfsDevice;
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
		this.___call({title:"initialize",
			data: {}
		});
	},
	uninit: function() {
		this.___call({title:"uninitialize",
			data: {}
		});
	},
	start: function(lowMajor, lowMinor, highMajor, highMinor) {
		var version = (lowMinor<<24)+(lowMajor<<16)+(highMinor<<8)+highMajor;
		var result = this.___call({title:"start", 
			data: { versionRequired: version }
		});

		return result;
	},
	cleanUp: function() {
		this.___call({title:"cleanUp",
			data: {}
		});
	}
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

exports.XfsMgr = inhertits(__XfsMgr, _XfsMgr);

/*
function XfsMgr(traceLevel, timeOut){
	__XfsMgr.apply(this, Array.prototype.slice.call(arguments));

	this.init = function () {
		//console.log(__XfsMgr.prototype.__call);
		__XfsMgr.prototype.__call.apply(this, ['initialize', "{}"]);
		//this.__call('initialize', "{}");
	}

	this.start = function(low, high) {
		console.log(this.__call);
		result = this.__call("start", low<<16|high);
		//this.traceLevel = this._traceLevel;
		//this.timeOut = this._timeOut;
		return result;
	}

	this.cleanUp=function() {
		result = this.__call("cleanUp", low<<16|high);
	}

	this.open=function(dev) {
		
	}

	set traceLevel(level) {
		this._traceLevel = level;
		this._xfs._setTraceLevel(level);
		return level;
	}

	get traceLevel() {
		return this._traceLevel;
	}
	
	set timeOut(timeOut) {
		this._timeOut = timeOut;
		this._xfs._setTimeOut(timeOut);
		return timeOut;
	}

	get timeOut() {
		return this._timeOut;
	}

};

function XfsDevice(logicalName, appName, level, timeout) {

	this._logicalName = logicalName;
	this._appName = appName;

	this._traceLevel = level | "WFS_TRACE_ALL_SPI";
	this._timeOut = timeOut | 5000;

	this._xfs = new _XfsDevice();

	// event: opened;
	this.open = function(high, low) {
		return this._xfs._open(this._logicalName, this._appName, high, low, this._traceLevel, this._timeOut);
	}

	this.query = function(title, data) {
		this._xfs._query(title, data);
	}

	this.execute = function(title, data) {
		this._xfs._execute(title, data);
	}

	this.lock = function() {
		this._xfs._lock();
	}

	this.unlock = function() {
		this._xfs._unlock();
	}

	this.cancel = function(id) {
		this._xfs._cancel(id);
	}
/*
	set traceLevel(level) {
		this._traceLevel = level;
		this._xfs._setTraceLevel(level);
		return level;
	}

	get traceLevel() {
		return this._traceLevel;
	}
	
	set timeOut(timeOut) {
		this._timeOut = timeOut;
		this._xfs._setTimeOut(timeOut);
		return timeOut;
	}

	get timeOut() {
		return this._timeOut;
	}

};


//exports.XfsMgr = mixin(__XfsMgr, _XfsMgr);
//XfsDevice = mixin(__XfsDevice, _XfsDevice);
XfsDevice = mixin(__XfsDevice, XfsDevice);
XfsMgr = mixin(__XfsMgr, XfsMgr);

exports.XfsMgr = XfsMgr;
*/
