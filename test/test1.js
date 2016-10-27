const xfs = require("../");
//console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
xmgr.on('initialize', ()=>{
	xmgr.start(3, 0, 3, 0);
});

xmgr.on('start', (version)=>{
	console.log(xmgr.traceLevel);
	console.log(xmgr.timeOut);

	xmgr.cleanUp();
});

xmgr.on('cleanUp', ()=>{
	xmgr.uninit();
});

xmgr.on('cleanUp.error', ()=>{
	xmgr.uninit();
});

var run = 3;
xmgr.on('win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});


xmgr.init();

