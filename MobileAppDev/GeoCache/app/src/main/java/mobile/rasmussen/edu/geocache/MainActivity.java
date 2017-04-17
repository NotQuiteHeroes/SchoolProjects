package mobile.rasmussen.edu.geocache;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    Button PlayButton;
    Button TreasureButton;
    Button ProfileButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        PlayButton = (Button) findViewById(R.id.ButtonPlay);
        PlayButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(MainActivity.this, PlayActivity.class));
            }
        });

        TreasureButton = (Button) findViewById(R.id.ButtonTreasures);
        TreasureButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(MainActivity.this, TreasureStorageActivity.class));
            }
        });

        ProfileButton = (Button) findViewById(R.id.ButtonProfile);
        ProfileButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(MainActivity.this, ProfileActivity.class));
            }
        });


    }
}
