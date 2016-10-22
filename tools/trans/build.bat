@echo off
set OLDDIR=%CD%
cd %~dp0

node index.js ../../include/xfs/pseudo.h ../../include/xfs/xfsapi.h ../../include/xfs/xfsadmin.h ../../include/xfs/xfsceu.h ../../include/xfs/xfspin.h ../../include/xfs/xfsalm.h ../../include/xfs/xfschk.h ../../include/xfs/xfsptr.h  ../../include/xfs/xfscim.h ../../include/xfs/xfssiu.h ../../include/xfs/xfsbcr.h ../../include/xfs/xfsconf.h ../../include/xfs/xfsspi.h ../../include/xfs/xfscam.h ../../include/xfs/xfsdep.h ../../include/xfs/xfsttu.h ../../include/xfs/xfscdm.h ../../include/xfs/xfsidc.h ../../include/xfs/xfsvdm.h | tee ../../src/xfs-trans.h

chdir /d %OLDDIR%