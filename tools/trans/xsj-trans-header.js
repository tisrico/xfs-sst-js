var __XfsDevice = require('bindings')('xsj').XfsDevice;
var __XfsMgr = require('bindings')('xsj').XfsMgr;

const mixin = require('mixin');

function inhertits(target, source) {
  for (var k in source.prototype) {
    target.prototype[k] = source.prototype[k];
  }
}

function _XfsMgr(traceLevel, timeOut){

	this.start=function(low, high)	{
		result = this._xfs._start(low, high);
		this.traceLevel = this._traceLevel;
		this.timeOut = this._timeOut;
		return result;
	}

	this.cleanUp=function() {
		//return  this._xfs._clean();
	}

	this.create=function(dev) {
		return this._xfs._newDevices(dev);
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
*/	
};

function _XfsDevice(logicalName, appName, level, timeout) {

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
*/	
};


exports.XfsMgr = mixin(__XfsMgr, _XfsMgr);
XfsDevice = mixin(__XfsDevice, _XfsDevice);
exports.XfsDevice = XfsDevice;
