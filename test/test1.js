const xfs = require("../");
console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

//console.log(xfs.XfsMgr);
var xmgr = new xfs.XfsMgr();
xmgr.on('ok', ()=>{
	console.log('ok');
	xmgr.cleanUp();
});

xmgr._send('ok');


//console.log(xmgr);
//xmgr._post('xxx', "ddd");

