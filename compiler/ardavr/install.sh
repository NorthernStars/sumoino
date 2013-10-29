# install the compiler
cd /data/data/jackpal.androidterm
cat /sdcard/busybox > busybox
chmod 777 ./busybox
./busybox gzip -d /sdcard/local.tar.gz
./busybox tar -xvf /sdcard/local.tar
# take out the trash
rm ./busybox
cd /sdcard
rm local.tar.gz ./busybox