const xfs = require("../");
console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
var appHandle = null;
var printer = null;

xmgr.on('initialize', ()=>{
	xmgr.start(3, 0, 3, 0);
	xmgr.createAppHandle();
});

xmgr.on("createAppHandle", (data)=>{
	console.log("handle", data);
	appHandle = data;
	xmgr.open('PTR', 3, 0, 3, 0, appHandle)
	//xmgr.destroyAppHandle(data);
	//xmgr.cleanUp();
});

xmgr.on('open.complete',  (data)=>{
	printer = data.object;
	console.log(printer);
	//console.log(require('util').inspect(printer.prototype, {showHidden: false, depth: null}));
	printer.status();
});

xmgr.on('start', (version)=>{
	console.log(xmgr.traceLevel);
	console.log(xmgr.timeOut);
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

