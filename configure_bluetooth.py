#!/bin/python
import bluetooth

print "Scanning nearby devices ..."
# scan for nearby devices and get the names and adresses
#devices = bluetooth.discover_devices(lookup_names = True)
#print "Found %d devices:" % len(devices)

# print out nearby devices
#for name, addr in devices:
#    print "%s - %s" % (addr, name)

name = "linvor"
addr = "00:12:09:25:90:82"

print "Opening socket ..."
# open the socket using the RFCOMM protocol
socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
print "Connecting to %s - %s" % (name, addr)
# connect to the address and port
socket.connect((addr, 1))

print "Sending data to socket ..."
# set response timeout
socket.settimeout(3)
# send the data
socket.send("AT")

print "Closing socket ..."
#close the socket
socket.close()
