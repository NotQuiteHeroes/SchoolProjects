package com.eckstein.paige.notifications;

import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;

public class Receiver extends BroadcastReceiver {
    String pkg = "com.eckstein.paige.lognotificationservice";
    String cls = "com.eckstein.paige.lognotificationservice.LogNotificationService";

    @Override
    public void onReceive(Context context, Intent intent)
    {
        Intent i = new Intent();
        if(intent.getAction().equals(Intent.ACTION_BATTERY_LOW)) {
            i.putExtra("log", "battery");
        }
        else if(intent.getAction().equals(Intent.ACTION_POWER_DISCONNECTED))
        {
            i.putExtra("log", "power");
        }
        else if(intent.getAction().equals(Intent.ACTION_CONFIGURATION_CHANGED))
        {
            i.putExtra("log", "configuration");
        }

        i.setComponent(new ComponentName(pkg, cls));
        context.startService(i);
    }
}
