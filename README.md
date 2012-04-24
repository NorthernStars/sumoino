# this library can be used to control 2 servo motors and 2 distance + 3 light sensors
# in the project you can also find the schematics for the arduino extensionboard

1) copy sumolib into your arduino libraries folder
2) restart arduino and press Sketch > Import Library... > Sumorobot
3) write some code xD (also the examples "Drive", "Avoid", "Opponent" are available)

# download the library to the tmp and copy the library to the installed arduino
cd /var/tmp
git clone http://github.com/silps/sumoino.git
sudo cp -R sumoino/Sumorobot /usr/share/arduino/libraries

# if you don't have arduino 1.0 you need to do this additional step
# this will rename the example file formats into the old arduino format
sudo for i in `find /usr/share/arduino/libraries/Sumorobot/examples -name *.ino`;do mv $i ${i%.*}.pde;done

# after everything is done, open arduino and enjoy xD
