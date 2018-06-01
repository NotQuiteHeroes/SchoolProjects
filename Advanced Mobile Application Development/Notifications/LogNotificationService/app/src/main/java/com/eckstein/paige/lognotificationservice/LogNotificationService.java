package com.eckstein.paige.lognotificationservice;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;
import android.provider.Settings;
import android.support.v4.app.NotificationCompat;

import java.io.FileOutputStream;
import java.io.IOException;


public class LogNotificationService extends Service {

    @Override
    public IBinder onBind(Intent intent)
    {
        return null;
    }

    @Override
    public int onStartCommand(Intent intent, int flags,  int startid) {
        if (intent != null) {
            writeToFile(intent);
            String type = intent.getStringExtra("log");
            if(type.equals("battery"))
            {
                batteryNotify();
            }
            else if(type.equals("configuration"))
            {
                configurationNotify();
            }
            else if(type.equals("power"))
            {
                powerNotify();
            }
        }

        return START_STICKY;
    }

    public void writeToFile(Intent intent)
    {
        String fileName = "logInfo";
        FileOutputStream output;
        String logInfo = intent.getStringExtra("log");
        try {
            output = openFileOutput(fileName, Context.MODE_APPEND);
            output.write(logInfo.getBytes());
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

        public void batteryNotify()
        {
            PendingIntent notificationIntent = PendingIntent.getActivity(this, 0,
                    new Intent(this, MainActivity.class),0);

            NotificationCompat.Builder mBuilder = (NotificationCompat.Builder) new NotificationCompat.Builder(this)
                    .setSmallIcon(R.mipmap.ic_launcher_round)
                    .setContentTitle("Battery Indicator")
                    .setTicker("Battery Indicator Alert")
                    .setContentText("Battery is below 20%. Please charge soon.")
                    .setSound(Settings.System.DEFAULT_NOTIFICATION_URI)
                    .setVibrate(new long[] {1000, 1000, 1000, 1000})
                    .setContentIntent(notificationIntent)
                    .setAutoCancel(true);



            NotificationManager mNotificationManager =
                    (NotificationManager)this.getSystemService(Context.NOTIFICATION_SERVICE);

            mNotificationManager.notify(1, mBuilder.build());
        }

    public void configurationNotify()
    {
        PendingIntent notificationIntent = PendingIntent.getActivity(this, 0,
                new Intent(this, MainActivity.class),0);

        NotificationCompat.Builder mBuilder = (NotificationCompat.Builder) new NotificationCompat.Builder(this)
                .setSmallIcon(R.mipmap.ic_launcher_round)
                .setContentTitle("Configuration Indicator")
                .setTicker("Configuration Indicator Alert")
                .setContentText("Configuration change detected.")
                .setSound(Settings.System.DEFAULT_NOTIFICATION_URI)
                .setVibrate(new long[] {1000, 1000, 1000, 1000})
                .setContentIntent(notificationIntent)
                .setAutoCancel(true);



        NotificationManager mNotificationManager =
                (NotificationManager)this.getSystemService(Context.NOTIFICATION_SERVICE);

        mNotificationManager.notify(1, mBuilder.build());
    }

    public void powerNotify()
    {
        PendingIntent notificationIntent = PendingIntent.getActivity(this, 0,
                new Intent(this, MainActivity.class),0);

        NotificationCompat.Builder mBuilder = (NotificationCompat.Builder) new NotificationCompat.Builder(this)
                .setSmallIcon(R.mipmap.ic_launcher_round)
                .setContentTitle("Power Indicator")
                .setTicker("Power Indicator Alert")
                .setContentText("Power disconnection detected.")
                .setSound(Settings.System.DEFAULT_NOTIFICATION_URI)
                .setVibrate(new long[] {1000, 1000, 1000, 1000})
                .setContentIntent(notificationIntent)
                .setAutoCancel(true);



        NotificationManager mNotificationManager =
                (NotificationManager)this.getSystemService(Context.NOTIFICATION_SERVICE);

        mNotificationManager.notify(1, mBuilder.build());
    }
}
