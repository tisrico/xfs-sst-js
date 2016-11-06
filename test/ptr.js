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
	console.log(result);
	//console.log(require('util').inspect(result, {showHidden: false, depth: null}));
}

var medias = [];

xmgr.on('open.complete',  (data)=>{
	printer = data.object.async();
	printer.status().finish(dumpResult);
	printer.capabilities().finish(dumpResult);

	printer.async().mediaList().finish((data)=>{
		dumpResult(data);
		medias = data.data;
		data.data.map((item)=>{
			printer.queryMedia(item).finish(dumpResult);
		});
	});

	printer.async().formList().finish((data)=>{
		dumpResult(data);

		data.data.map((item)=>{
			dumpResult(item);
			printer.queryForm(item).finish(dumpResult);
			printer.queryField(item).finish(dumpResult);
			medias.map((media)=>{
				var printData = {x:1, y:"2.0", z:"z", u:true, v:0.1, n:0, m:"", k:undefined};
				printer.printForm(item, media, printData).finish(function() {
					printer.controlMedia("WFS_PTR_CTRLEJECT").finish(dumpResult);
				});
			});
		});
	});


	printer.controlMedia("WFS_PTR_CTRLEJECT").finish(dumpResult);

	setTimeout(()=>{
		printer.on('PtrStatus', (status)=>{
			printer.close();
			printer.on('close.compelete', ()=> {
				xmgr.cleanUp();
				xmgr.uninit();
			});
		});
		printer.async().status().finish(dumpResult);
	}, 5000);
	
});

var run = 3;
xmgr.on('win.exit', ()=> {
	if(run--) {
		setTimeout(()=>{xmgr.init();}, 1000);
	}
});

xmgr.init();

