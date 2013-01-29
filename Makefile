download_32:
	wget http://dl.google.com/android/adt/adt-bundle-linux-x86.zip
	unzip adt-bundle-linux-x86.zip
	rm adt-bundle-linux-x86.zip
init_32:
	export PATH=$PATH:"$pwd"/adt-bundle-linux-x86_64/sdk/platform-tools/
	export PATH=$PATH:"$pwd"/adt-bundle-linux-x86_64/sdk/tools/
download_64:
	wget http://dl.google.com/android/adt/adt-bundle-linux-x86_64.zip
	unzip adt-bundle-linux-x86_64.zip
	rm adt-bundle-linux-x86_64.zip
init_64:
	export PATH=$PATH:"$pwd"/adt-bundle-linux-x86_64/sdk/platform-tools/
	export PATH=$PATH:"$pwd"/adt-bundle-linux-x86_64/sdk/tools/
init_project:
	mkdir -p libs 
	wget -P libs http://amarino.googlecode.com/files/AmarinoLibrary_v0_55.jar
	android update project --name Moodrobotplugin --target 1 --path `pwd`
init_arduino:
	wget -P /usr/share/arduino/libraries/ http://amarino.googlecode.com/files/MeetAndroid_4.zip
	unzip -d /usr/share/arduino/libraries/ /usr/share/arduino/libraries/MeetAndroid_4.zip
	rm /usr/share/arduino/libraries/MeetAndroid_4.zip
install_amarino:
	wget http://amarino.googlecode.com/files/Amarino_2_v0_55.apk
	adb install Amarino_2_v0_55.apk
	rm Amarino_2_v0_55.apk
all:
	ant debug
install:
	adb uninstall amarino.plugin.moodrobot && adb install bin/Moodrobotplugin-debug.apk
