package amarino.plugin.moodrobot;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

import android.net.Uri;
import android.widget.Toast;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import android.content.res.AssetFileDescriptor;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.media.MediaRecorder;
import android.media.AudioRecord;
import android.media.AudioFormat;

import android.util.Log;
import android.content.Context;
import android.preference.PreferenceManager;

import at.abraxas.amarino.Amarino;
import at.abraxas.amarino.AmarinoIntent;
import at.abraxas.amarino.plugin.BackgroundService;

public class MyBackgroundService extends BackgroundService implements SensorEventListener {
	
	private static final String TAG = "MyBackgroundService";
	private static final boolean DEBUG = true;
	
	public MyBackgroundService() {
		super(TAG, DEBUG); 
	}
	
	private final int HAPPYDELAY = 3000, UPDATEYDELAY = 10;
	private boolean isHappy = true;

	private SensorManager sensorManager;
	private Sensor accSensor;
	private MediaRecorder recorder;

	private long startHappy = -5000, updateY = 0;
	private float initialY = 0;
	
	@Override
	public boolean init() {
		pluginId = PreferenceManager.getDefaultSharedPreferences(this)
			.getInt(AmarinoIntent.EXTRA_PLUGIN_ID, -1);
		
		sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        accSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        sensorManager.registerListener(this,accSensor,SensorManager.SENSOR_DELAY_GAME);

		playSound("go.mp3");

        try {
	        recorder = new MediaRecorder();
		 	recorder.setAudioSource(MediaRecorder.AudioSource.MIC);
		 	recorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
		 	recorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
		 	recorder.setOutputFile("/dev/null");
		 	recorder.prepare();
			recorder.start();
		} catch ( Exception e ) {
			Toast.makeText(this, "recorder fail:"+e.getMessage(), Toast.LENGTH_SHORT).show();
			if (DEBUG) Log.d(TAG, "recorder failed");
		}

		return true;
	}

	
	@Override
	public void onAccuracyChanged(Sensor sensor, int accuracy) {
	    // TODO Auto-generated method stub
	}

	@Override
	public void onSensorChanged(SensorEvent event) {
		int amplitude = recorder.getMaxAmplitude();
		//Amarino.sendDataToArduino(this, DEVICE_ADDRESS, 'r', recorder.getMaxAmplitude()/10 );
		float y = 0;
		if ( event.sensor.getType() == Sensor.TYPE_ACCELEROMETER ) {
		    y = event.values[1];
		}

		if ( System.currentTimeMillis() - updateY > UPDATEYDELAY ) {
			initialY = y;
			updateY = System.currentTimeMillis();
		}

		// check if still happy or just got happy
		if ( amplitude > 10000 || Math.abs(initialY - y) > 3.8 ) {
			Toast.makeText(this, "amp: "+amplitude+" Y: "+y+" inital: "+initialY, Toast.LENGTH_SHORT).show();
			// when we came here with sad state
			if ( isHappy == false ) {
				isHappy = true;
				playSound("happy.mp3");
				// send to arduino
				sendState(isHappy);
			}
			initialY = y;
			startHappy = System.currentTimeMillis();
		// happy state is expired
		} else if ( isHappy == true && (System.currentTimeMillis() - startHappy > HAPPYDELAY) ) {
			isHappy = false;
			playSound("sad.mp3");
			// send to arduino
			sendState(isHappy);
		}
	}

	private void sendState(boolean state) {
		if (DEBUG) Log.d(TAG, "0 for sad, 1 happy: " + state );
		Amarino.sendDataFromPlugin(MyBackgroundService.this, pluginId, state);
	}

	private void playSound(String soundFile) {
		try {
			AssetFileDescriptor afd = getAssets().openFd(soundFile);
			MediaPlayer mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());
			mediaPlayer.prepare();
			mediaPlayer.start();
			mediaPlayer.setOnCompletionListener(new OnCompletionListener() {
                @Override
                public void onCompletion(MediaPlayer mp) {
                    // TODO Auto-generated method stub
                    mp.release();
                }
            }); 
		} catch (Exception e) {
			Toast.makeText(this, "player fail:"+e.getMessage(), Toast.LENGTH_SHORT).show();
		}
	}
	
	@Override
	public void cleanup() {
		recorder.stop();
		recorder.release();
		sensorManager.unregisterListener(this);
	}

}
