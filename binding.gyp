{
  "targets": [
    {
      "target_name": "xsj",
      "sources": [ "src/xsj.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
		    "include",
        "include/xfs",
      ]
    }
  ]
}
