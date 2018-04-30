const xfs = require("../");
//console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
var appHandle = null;
var idc = null;

xmgr.on('xsj.initialize', ()=>{
	xmgr.start(3, 0, 3, 0);
	appHandle = xmgr.createAppHandle().handle;
	console.log(xmgr.traceLevel);
	console.log(xmgr.timeOut);
	var res = xmgr.open('CDM', 3, 0, 3, 0, appHandle);
});

function dumpResult(result) {
	//console.log(result);
	//console.log(require('util').inspect(result, {showHidden: false, depth: null}));
}

var forms = [];

xmgr.on('xsj.open.complete',  (data)=>{
	idc = data.object.async();
	idc.status().then(dumpResult);
	idc.capabilities().then(dumpResult);

	idc.presentStatus().then(()=>
		setTimeout(()=>{
			idc.close();
			idc.on('xsj.close.compelete', ()=> {
				xmgr.cleanUp();
				xmgr.uninit();
			});
		}, 1500)
	);
	
});


var run = 3;
xmgr.on('xsj.win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

