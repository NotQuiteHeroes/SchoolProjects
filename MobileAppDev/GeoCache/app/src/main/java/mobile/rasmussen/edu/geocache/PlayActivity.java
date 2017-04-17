package mobile.rasmussen.edu.geocache;


import android.content.Intent;
import android.content.res.Resources;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Button;

public class PlayActivity extends AppCompatActivity {

    TextView currentCoordinates;
    TextView currentLongitude;
    TextView currentLatitude;

    Button shawButton;
    Button wildButton;
    Button sleeplessButton;
    Button songbirdButton;
    Button fruitButton;

    static Double longitude;
    static Double latitude;

    GPSTracker gps;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play);

        currentLongitude = (TextView) findViewById(R.id.CurrentLongitude);
        currentLatitude = (TextView) findViewById(R.id.CurrentLatitude);

        shawButton = (Button) findViewById(R.id.ButtonShaw);
        shawButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(PlayActivity.this, TreasureActivity.class);
                intent.putExtra("TreasureType", 1);
                startActivity(intent);
            }
        });

        wildButton = (Button) findViewById(R.id.ButtonWild);
        wildButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(PlayActivity.this, TreasureActivity.class);
                intent.putExtra("TreasureType", 2);
                startActivity(intent);
            }
        });

        sleeplessButton = (Button) findViewById(R.id.ButtonSleepless);
        sleeplessButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(PlayActivity.this, TreasureActivity.class);
                intent.putExtra("TreasureType", 3);
                startActivity(intent);
            }
        });

        songbirdButton = (Button) findViewById(R.id.ButtonSongbird);
        songbirdButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(PlayActivity.this, TreasureActivity.class);
                intent.putExtra("TreasureType", 4);
                startActivity(intent);
            }
        });

        fruitButton = (Button) findViewById(R.id.ButtonFruit);
        fruitButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                Intent intent = new Intent(PlayActivity.this, TreasureActivity.class);
                intent.putExtra("TreasureType", 5);
                startActivity(intent);
            }
        });

        gps = new GPSTracker(PlayActivity.this);

        if (gps.canGetLocation()) {
            latitude = gps.getLatitude();
            longitude = gps.getLongitude();

            Resources res = getResources();
            String tempLong = String.format(res.getString(R.string.StringCurrentLong), longitude);
            String tempLat = String.format(res.getString(R.string.StringCurrentLat), latitude);

            currentLongitude.setText(tempLong);
            currentLatitude.setText(tempLat);
        } else {
            gps.showSettingsAlert();
        }
    }
}