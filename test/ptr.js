const xfs = require("../");
//console.log(require('util').inspect(xfs.XfsMgr.prototype, {showHidden: false, depth: null}));
//console.log(require('util').inspect(xfs.XfsDevice.prototype, {showHidden: false, depth: null}));

var xmgr = new xfs.XfsMgr();
var appHandle = null;
var printer = null;

xmgr.on('xsj.initialize', ()=>{
	xmgr.start(3, 0, 3, 0);
	appHandle = xmgr.createAppHandle().handle;
	console.log(xmgr.traceLevel);
	console.log(xmgr.timeOut);
	var res = xmgr.open('RPTR', 3, 0, 3, 0, appHandle);
});

function dumpResult(result) {
	console.log(result);
	//console.log(require('util').inspect(result, {showHidden: false, depth: null}));
}

var medias = [];

xmgr.on('xsj.open.complete',  (data)=>{
	printer = data.object.async();
	printer.status().then(dumpResult);
	printer.capabilities().then(dumpResult);

	printer.async().mediaList().then((data)=>{
		dumpResult(data);
		medias = data.data.mediaList;
		medias.map((item)=>{
			printer.queryMedia(item).then(dumpResult);
		});
	});

	printer.async().formList().then((data)=>{
		dumpResult(data);

		data.data.formList.map((item)=>{
			dumpResult(item);
			printer.queryForm(item).then(dumpResult);
			printer.queryField(item).then(dumpResult);
			medias.map((media)=>{
				var printData = {x:1, y:"2.0", z:"z", u:true, v:0.1, n:0, m:"", k:undefined};
				printer.printForm(item, media, printData).then(function() {
					printer.controlMedia("WFS_PTR_CTRLEJECT").then(dumpResult);
				});
			});
		});
	});


	printer.controlMedia("WFS_PTR_CTRLEJECT").then(dumpResult);

	setTimeout(()=>{
		printer.on('xsj.PtrStatus', (status)=>{
			printer.close();
			printer.on('xsj.close.compelete', ()=> {
				xmgr.cleanUp();
				xmgr.uninit();
			});
		});
		printer.async().status().then(dumpResult);
	}, 5000);
	
});

var run = 3;
xmgr.on('xsj.win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

