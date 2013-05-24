export PATH := $(PATH):/home/silbo/Downloads/adt-bundle-linux-x86_64/sdk/platform-tools/
export PATH := $(PATH):/home/silbo/Downloads/adt-bundle-linux-x86_64/sdk/tools/

all:
	ant debug
	adb uninstall org.apache.cordova.example
	adb install bin/cordovaExample-debug.apk
