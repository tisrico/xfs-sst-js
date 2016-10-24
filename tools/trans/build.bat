@echo off
set OLDDIR=%CD%
cd %~dp0

node index.js cspace ../../include/xfs/pseudo.h ../../include/xfs/xfsapi.h ../../include/xfs/xfsadmin.h ../../include/xfs/xfsceu.h ../../include/xfs/xfspin.h ../../include/xfs/xfsalm.h ../../include/xfs/xfschk.h ../../include/xfs/xfsptr.h  ../../include/xfs/xfscim.h ../../include/xfs/xfssiu.h ../../include/xfs/xfsbcr.h ../../include/xfs/xfsconf.h ../../include/xfs/xfsspi.h ../../include/xfs/xfscam.h ../../include/xfs/xfsdep.h ../../include/xfs/xfsttu.h ../../include/xfs/xfscdm.h ../../include/xfs/xfsidc.h ../../include/xfs/xfsvdm.h ../../include/xfs/xfsapi_xsj.h ../../include/xfs/xfsadmin_xsj.h ../../include/xfs/xfsceu_xsj.h ../../include/xfs/xfspin_xsj.h ../../include/xfs/xfsalm_xsj.h ../../include/xfs/xfschk_xsj.h ../../include/xfs/xfsptr_xsj.h  ../../include/xfs/xfscim_xsj.h ../../include/xfs/xfssiu_xsj.h ../../include/xfs/xfsbcr_xsj.h ../../include/xfs/xfsconf_xsj.h ../../include/xfs/xfsspi_xsj.h ../../include/xfs/xfscam_xsj.h ../../include/xfs/xfsdep_xsj.h ../../include/xfs/xfsttu_xsj.h ../../include/xfs/xfscdm_xsj.h ../../include/xfs/xfsidc_xsj.h ../../include/xfs/xfsvdm_xsj.h | tee ../../src/xfs-trans.h

chdir /d %OLDDIR%