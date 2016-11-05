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

function dumpResult(result) {
	//console.log(result);
	console.log(require('util').inspect(result, {showHidden: false, depth: null}));
}

xmgr.on('open.complete',  (data)=>{
	printer = data.object.async();
	printer.queryField('RPTR_BMP', '').finish(dumpResult);
/*
	printer.status();
	printer.capabilities();
	printer.queryForm();
	printer.queryMedia();

	printer.async().formList().finish(dumpResult);
	printer.async().mediaList().finish(dumpResult);
	printer.controlMedia("WFS_PTR_CTRLEJECT").finish(dumpResult);
	printer.capabilities().finish(dumpResult);
	printer.async().status().finish(dumpResult);

	printer.on('PtrStatus', (status)=>{
		printer.close();
		printer.on('close.compelete', ()=> {
			xmgr.cleanUp();
			xmgr.uninit();
		});
	});
*/
});

var run = 3;
xmgr.on('win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

