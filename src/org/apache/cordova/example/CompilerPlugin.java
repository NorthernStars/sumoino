package org.apache.cordova.example;

import java.io.File;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.lang.Runtime;

import android.content.Context;
import android.os.Environment;
import android.util.Log;
import android.widget.Toast;

import org.apache.cordova.api.CordovaPlugin;
import org.apache.cordova.api.PluginResult;
import org.apache.cordova.api.PluginResult.Status;
import org.apache.cordova.api.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

import at.abraxas.amarino.Amarino;

public class CompilerPlugin extends CordovaPlugin {

	private static final String TAG = "CompilerPlugin";
	private static final String DEVICE_ADDRESS = "00:12:09:25:90:82";
	private static final int TOAST_MESSAGE_INDEX = 0;
	public static Context context;

	@Override
	public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
		
		/*
		Amarino.connect(context, DEVICE_ADDRESS);
		BTFile data2 = new BTFile( "/sdcard/sumorobot/main.hex", false );
		try {
			Amarino.sendDataToArduino(context, DEVICE_ADDRESS, 'F', data2.OpenFile());
		} catch ( Exception ex ) {
			Toast.makeText(context, "error: " + ex.getMessage(), Toast.LENGTH_LONG);
		}
		Amarino.disconnect(context, DEVICE_ADDRESS);
		*/

		// when compile action was sent
		if ( "compile".equals(action) ) {
			Process process = null;
			try {
				// get the root directory of SD card
				File sdcard = Environment.getExternalStorageDirectory();

				// open the code file which is to be compiled
				BTFile data = new BTFile( "/sdcard/sumorobot/main.cpp", false );
				// add necessary lines to the file
				data.writeToFile( "#include <Arduino.h>\n" + args.getString(0) );

				// start the compiling process
				Toast.makeText(context, "Starting compile ...", Toast.LENGTH_SHORT).show();
				process = Runtime.getRuntime().exec("sh make.sh", null, new File("/sdcard/sumorobot/"));
				Toast.makeText(context, "Compile started", Toast.LENGTH_SHORT).show();
				
				// read all the std in and error
				BufferedReader stdInput = new BufferedReader(new
        InputStreamReader(process.getInputStream()));
 
     		BufferedReader stdError = new BufferedReader(new
        InputStreamReader(process.getErrorStream()));
		    String line, output = "", errors = "";

       	while ((line = stdInput.readLine()) != null) {
      		//if (line.contains("main"))
     			output = line;
       	}
       	while ((line = stdError.readLine()) != null) {
       		//if (line.contains("main"))
     			errors = line;
       	}
				
				// close the streams
				stdInput.close();
		    stdError.close();
				process.getOutputStream().close();
        process.getInputStream().close();
        process.getErrorStream().close();
        // wait for the compile process to finish
     		process.waitFor();

       	output += "\nexit value:" + process.exitValue();
       	output += "\nexit code: " + process.waitFor();

       	// show the std input and error
				Toast.makeText(context, "Compile output: " + output, Toast.LENGTH_SHORT).show();
				Toast.makeText(context, "Compile errors: " + errors, Toast.LENGTH_SHORT).show();
				//toast = Toast.makeText(context, "Compile successful, exit value: "+output, Toast.LENGTH_SHORT);
			} catch (Exception e) {
				// in case of error, the compiler was probably not installed
				Toast.makeText(context, "Compiler not installed", Toast.LENGTH_SHORT).show();
			} finally {
				// finally try to destroy the compile process
				if (process != null) 
					process.destroy();
			}
		// when any other action was sent
		} else {
			// show invalid action message
		  Toast.makeText(context, "Invalid action", Toast.LENGTH_SHORT).show();
		  return false;
		}

		// send back the results
		callbackContext.success("result");
		return true;
	}

}