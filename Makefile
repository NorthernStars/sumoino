export PATH := $(PATH):/home/silbo/Downloads/adt-bundle-linux-x86_64/sdk/platform-tools/
export PATH := $(PATH):/home/silbo/Downloads/adt-bundle-linux-x86_64/sdk/tools/

all: compile uninstall install

compile:
	ant debug

uninstall:
	adb uninstall org.apache.cordova.example

install:
	adb install bin/cordovaExample-debug.apk
