const xfs = require("../");
//console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
var appHandle = null;
var printer = null;

xmgr.on('initialize', ()=>{
	xmgr.start(3, 0, 3, 0);
	appHandle = xmgr.createAppHandle().handle;
	console.log(xmgr.traceLevel);
	console.log(xmgr.timeOut);
	var res = xmgr.open('PTR', 3, 0, 3, 0, appHandle);
});

xmgr.on('open.complete',  (data)=>{
	printer = data.object;
	printer.capabilities();
	printer.status();
});

xmgr.on('start', (version)=>{
});

xmgr.on('cleanUp', ()=>{
	xmgr.uninit();
});

xmgr.on('cleanUp.*', ()=>{
	xmgr.uninit();
});

var run = 3;
xmgr.on('win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

