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

public class CompilerPlugin extends CordovaPlugin {

	private static final String TAG = "CompilerPlugin";
	private static final int TOAST_MESSAGE_INDEX = 0;
	public static Context context;

	@Override
	public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
		if ( "compile".equals(action) ) {
			Process process = null;
			try {
				File sdcard = Environment.getExternalStorageDirectory();
				String[] commands = {"su", "-c", "sh make.sh"};
				process = Runtime.getRuntime().exec("sh make.sh", null, new File("/sdcard/sumorobot/"));
				
				BufferedReader stdInput = new BufferedReader(new
                	InputStreamReader(process.getInputStream()));
 
           		BufferedReader stdError = new BufferedReader(new
                	InputStreamReader(process.getErrorStream()));
		       	String line, output = "", errors = "";

		       	while ((line = stdInput.readLine()) != null) {
		       		//if (line.contains("main"))
		       			output += line;
		       	}
		       	while ((line = stdError.readLine()) != null) {
		       		//if (line.contains("main"))
		       			errors += line;
		       	}
				
				stdInput.close();
		       	stdError.close();
				process.getOutputStream().close();
           		process.getInputStream().close();
           		process.getErrorStream().close();
           		process.waitFor();

		       	output += "exit value:" + process.exitValue();
		       	output += "exit code: " + process.waitFor();

				Toast.makeText(context, "Compile output: "+output, Toast.LENGTH_LONG).show();
				Toast.makeText(context, "Compile errors: "+errors, Toast.LENGTH_LONG).show();
			} catch (Exception e) {
				Toast.makeText(context, "Compiler not installed", Toast.LENGTH_LONG).show();
			} finally {
				try { process.destroy(); } catch (Exception e) {}
			}
		} else {
		  	Toast.makeText(context, "Invalid action", Toast.LENGTH_SHORT).show();
		  	return false;
		}

		callbackContext.success("result");
		return true;
	}

}