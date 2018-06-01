package com.eckstein.paige.directions;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    EditText source;
    EditText destination;
    Button getDirections;
    TextView directionsView;
    ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        source = findViewById(R.id.source);
        destination = findViewById(R.id.destination);
        getDirections = findViewById(R.id.directionsButton);
        directionsView = findViewById(R.id.directionsDisplay);
        progressBar = findViewById(R.id.progressBar);
        progressBar.setVisibility(View.GONE);

        getDirections.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String sourceText = source.getText().toString();
                String destinationText = destination.getText().toString();
                String api = getResources().getString(R.string.google_maps_key);

                AsyncTaskRunner asyncTask = new AsyncTaskRunner(new AsyncResponse()
                {
                    @Override
                    public void processFinish(ArrayList<String> directions)
                    {
                        for(String direction : directions)
                        {
                            directionsView.append(direction + "\n");
                        }
                    }
                }, sourceText, destinationText, api);
                asyncTask.setProgressBar(progressBar);
                asyncTask.execute("");
            }
        });

    }
}


