const events = require('events');
const mixin = require('mixin');

function inhertits(target, source) {
  for (var k in source.prototype) {
    target.prototype[k] = source.prototype[k];
  }
}

function messaging() {
}

messaging.prototype = {
  _post: function(evt) {
   var args = arguments;
   setImmediate(()=> {
     this.emit.apply(this, args);
  });
 },

 _send:function(evt) {
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
