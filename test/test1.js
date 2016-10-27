const xfs = require("../");
require('console-stamp')(console, '[HH:MM:ss.l]');
//console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
xmgr.on('initialize', ()=>{
	console.log('initialize');
	xmgr.start(3, 3);
});

xmgr.on('start', ()=>{
	console.log('start');
	xmgr.cleanUp();
});

xmgr.on('cleanUp', ()=>{
	console.log('cleanUp');
	xmgr.uninit();
});

xmgr.on('cleanUp.error', ()=>{
	console.log('cleanUp.error');
	xmgr.uninit();
});

xmgr.on('win.start', ()=> {
	console.log('win.start');
});

var run = 3;
xmgr.on('win.exit', ()=> {
	console.log('win.exit');
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.on('console.log', (log)=>{
	console.log(log);
});

xmgr.on('console.info', (log)=>{
	console.info(log);
});

xmgr.on('console.warn', (log)=>{
	console.warn(log);
});

xmgr.on('console.error', (log)=>{
	console.error(log);
});

xmgr.on('console.assert', (log)=>{
	console.assert(0, log);
});

xmgr.init();
