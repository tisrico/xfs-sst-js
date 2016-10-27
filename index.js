const events = require('events');
const mixin = require('mixin');
const util = require('util');
require('console-stamp')(console, 'HH:MM:ss.l');

function inhertits(target, source) {
  for (var k in source.prototype) {
    target.prototype[k] = source.prototype[k];
  }
}

function messaging() {
}

messaging.prototype = {
  _logger: function(title, message) {
    if(!title.match(/console\..*/g)) {
      if(message.length) {
        console.log(util.format('event:%s, data:%s', title, message));
      }
      else {
       console.log(util.format('event:%s', title));
      }
    }
    else {
      if(title == "console.log") {
        console.log(message);
      }
      else if(title == "console.info") {
        console.info(message);
      }
      else if(title == "console.warn") {
        console.warn(message);
      }
      else if(title == "console.error") {
        console.error(message);
      }
      else if(title == "console.assert") {
        console.assert(0, message);
      }
      return;
    }
  },

  _post: function(evt) {
  var args = arguments;
  setImmediate(()=> {
    this._logger(args[0], args[1]);
    this.emit.apply(this, args);
  });
},

 _send:function(evt) {
    this._logger(arguments[0], arguments[1]);
    this.emit.apply(this, arguments);
 }
}

function load (module) {

  var addon =  require(module);
  for(var ix in addon) {

    var a = addon[ix];
    if(typeof(a) != 'function')
      continue;

     //a = mixin(a, messaging);
     //a = mixin(a, events);
     inhertits(a, messaging);
     inhertits(a, events);

     exports[a.name] = a;
  }
  
  return addon;
}

load('./xsj-trans.js');
//console.log('exports', exports.XfsMgr.prototype);
