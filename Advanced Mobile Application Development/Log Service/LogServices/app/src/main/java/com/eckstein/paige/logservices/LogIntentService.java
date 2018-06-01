package com.eckstein.paige.logservices;

import android.app.IntentService;
import android.content.Intent;
import android.content.Context;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;


public class LogIntentService extends IntentService {

    String fileName = "logInfo";
    FileOutputStream output;

    public LogIntentService() {
        super("LogIntentService");
    }


    @Override
    protected void onHandleIntent(Intent intent) {
        if (intent != null) {
            String logInfo = intent.getStringExtra("log");
            try {
                output = openFileOutput(fileName, Context.MODE_APPEND);
                output.write(logInfo.getBytes());
                output.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }

}
