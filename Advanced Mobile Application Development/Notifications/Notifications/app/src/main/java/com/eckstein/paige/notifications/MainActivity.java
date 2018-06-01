package com.eckstein.paige.notifications;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        BroadcastReceiver br = new Receiver();
        IntentFilter i = new IntentFilter(Intent.ACTION_CONFIGURATION_CHANGED);
        getApplicationContext().registerReceiver(br, i);

    }
}
