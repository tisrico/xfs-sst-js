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
	var res = xmgr.open('RPTR', 3, 0, 3, 0, appHandle);
});

xmgr.on('open.complete',  (data)=>{
	printer = data.object;
	
	printer.async().mediaList().finish(function(forms) {
		console.log("mmmm", forms);
	});

	printer.async().status().finish(function(status) {
		console.log("nnnn", status);
	});

	printer.on('PtrStatus', (status)=>{
		//console.log("xxx", status);
		printer.close();
		printer.on('close.compelete', ()=> {
			xmgr.cleanUp();
			xmgr.uninit();
		});
	});

});

var run = 3;
xmgr.on('win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

