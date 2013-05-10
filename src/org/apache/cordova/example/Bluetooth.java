/*
  MultiColorLamp - Example to use with Amarino
  Copyright (c) 2009 Bonifaz Kaufmann. 
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
package org.apache.cordova.example;

import android.content.Context;
import android.app.Activity;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.View;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.SeekBar.OnSeekBarChangeListener;

import at.abraxas.amarino.Amarino;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import android.app.AlertDialog;

public class Bluetooth {
	
	private static final String TAG = "Bluetooth";
	
	/* TODO: change the address to the address of your Bluetooth module
	 * and ensure your device is added to Amarino
	 */
	private static final String DEVICE_ADDRESS = "00:12:09:25:90:82";

    public void connect() {
    	// connect to Arduino
		Amarino.connect(this, DEVICE_ADDRESS);
    }

	public void send(byte b) {
		// send byte to Arduino
		Amarino.sendDataToArduino(this, DEVICE_ADDRESS, b, 0);
	}

	public void disconnect() {
		// disconnect from Arduino
		Amarino.disconnect(this, DEVICE_ADDRESS);
	}
	
}
