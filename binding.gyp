{
  "targets": [
    {
      "target_name": "xsj",
      "sources": [ "src/xsj.cc", "src/window.cc", "src/xfsdevice.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
		    "include",
        "include/xfs",
      ],
      'library_dirs': ["lib"],
      'libraries':[
        "msxfs.lib", "xfs_conf.lib", "xfs_supp.lib"
      ]
    }
  ]
}
