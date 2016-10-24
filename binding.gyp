{
  "targets": [
    {
      "target_name": "xsj",
      "sources": [ "src/xsj.cc" ],
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
