package org.apache.cordova.example;

import java.io.File;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.DataOutputStream;
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
			try {
				File sdcard = Environment.getExternalStorageDirectory();
				String[] cmd = {"cd", "/sdcard/download/ && sh make.sh"};
				//String end = "";
				
				String[] shellInput = new String[]{"/system/bin/sh", "-c", "cd "+sdcard+" && /data/data/jackpal.androidterm/local/bin/make all"};
				//String[] shellInput = new String[]{"/system/bin/sh/", "-c", "echo 'yoyo'> /sdcard/Download/yoyo.txt"};
				//Process sh = Runtime.getRuntime().exec("/data/data/jackpal.androidterm/local/bin/make all", null, sdcard);
				//Process sh = Runtime.getRuntime().exec("/system/bin/sh -c cd "+sdcard+" && /data/data/jackpal.androidterm/local/bin/make all");
		        
				Process sh = Runtime.getRuntime().exec("sh make.sh", null, new File("/sdcard/sumorobot/"));
				
				//DataOutputStream os = new DataOutputStream(sh.getOutputStream());
				//os.writeBytes("/sdcard/download/make.sh");
				//os.flush();
				
				BufferedReader br = new BufferedReader(new InputStreamReader(sh.getInputStream()));
		       	String line;
		       	String end = "";

		       	//while (br.ready() == false) {}
		       	while ((line = br.readLine()) != null) {
		       		//if (line.contains("main"))
		       			end += line + '\n';
		       			Thread.sleep(10 * 1000);
		       	}
		       	end += "exit value:" + sh.exitValue();

		       	for (int i=0; i < 7; i++)
					Toast.makeText(context, "Compile successful: "+end, Toast.LENGTH_LONG).show();
			} catch (Exception e) {
				Toast.makeText(context, "Compile failed: "+e.getMessage(), Toast.LENGTH_LONG).show();
			}
		} else {
		  		Toast.makeText(context, "Invalid action", Toast.LENGTH_SHORT).show();
		  		return false;
		}

		callbackContext.success("result");
		return true;
	}

}