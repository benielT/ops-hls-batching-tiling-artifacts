APPDIR=/home/x_thileeb/repos/ops-hls-batching-new/codegen_apps/tiling/poisson2d/u280_project/maxtile_8192_interleave_p8
SCRATCH=/var/tmp/$USER/poisson2d_maxtile8192_p8
du -sh $SCRATCH/build
du -sh $SCRATCH/build/hw/temp_dir
ls -la $SCRATCH/build/hw/poisson2d.xclbin
df -h $APPDIR