package mobile.rasmussen.edu.geocache;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Button;
import android.widget.Toast;
import android.widget.TextView;
import android.content.Intent;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class TreasureStorageActivity extends AppCompatActivity
{

    EditText treasureName;
    EditText dateFound;
    EditText longitude;
    EditText latitude;
    EditText treasureDescription;

    TextView textView;

    Button saveButton;
    Button loadButton;
    Button backButton;
    Button homeButton;

    String treasureNameValue;
    String dateFoundValue;
    String longitudeValue;
    String latitudeValue;
    String treasureDescriptionValue;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_treasurestorage);

        //deleteFile("saved_treasures.txt");

        treasureName = (EditText) findViewById(R.id.Treasure);
        dateFound = (EditText) findViewById(R.id.Date);
        longitude = (EditText) findViewById(R.id.Longitude);
        latitude = (EditText) findViewById(R.id.Latitude);
        treasureDescription = (EditText) findViewById(R.id.Description);

        textView = (TextView) findViewById(R.id.textView);

        treasureName.setVisibility(View.VISIBLE);
        dateFound.setVisibility(View.VISIBLE);
        longitude.setVisibility(View.VISIBLE);
        latitude.setVisibility(View.VISIBLE);
        treasureDescription.setVisibility(View.VISIBLE);

        textView.setVisibility(View.GONE);

        backButton = (Button) findViewById(R.id.BackButton);
        backButton.setVisibility(View.GONE);


        saveButton = (Button) findViewById(R.id.SaveButton);
        saveButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                treasureNameValue = treasureName.getText().toString();
                dateFoundValue = dateFound.getText().toString();
                longitudeValue = longitude.getText().toString();
                latitudeValue = latitude.getText().toString();
                treasureDescriptionValue = treasureDescription.getText().toString();

                saveData(treasureNameValue);
                saveData(dateFoundValue);
                saveData(longitudeValue);
                saveData(latitudeValue);
                saveData(treasureDescriptionValue);
            }

        });

        loadButton = (Button) findViewById(R.id.loadButton);
        loadButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                treasureName.setVisibility(View.INVISIBLE);
                dateFound.setVisibility(View.INVISIBLE);
                longitude.setVisibility(View.INVISIBLE);
                latitude.setVisibility(View.INVISIBLE);
                treasureDescription.setVisibility(View.INVISIBLE);
                backButton.setVisibility(View.VISIBLE);

                loadData();
            }
        });


        backButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                textView.setVisibility(View.INVISIBLE);

                treasureName.setVisibility(View.VISIBLE);
                dateFound.setVisibility(View.VISIBLE);
                longitude.setVisibility(View.VISIBLE);
                latitude.setVisibility(View.VISIBLE);
                treasureDescription.setVisibility(View.VISIBLE);

                backButton.setVisibility(View.GONE);
            }
        });

        homeButton = (Button) findViewById(R.id.HomeButton);
        homeButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(TreasureStorageActivity.this, MainActivity.class));
            }
        });


    }

    public void saveData(String data)
    {


        try
        {
            FileOutputStream outPut = openFileOutput("saved_treasures.txt", MODE_APPEND);
            outPut.write(data.getBytes());
            outPut.write('\n');
            outPut.close();
            Toast.makeText(getApplicationContext(), "Saved", Toast.LENGTH_SHORT).show();

            treasureName.setText("");
            dateFound.setText("");
            longitude.setText("");
            latitude.setText("");
            treasureDescription.setText("");
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

    }

    public void loadData()
    {

        try
        {
            String toLoad;

            FileInputStream inPut = openFileInput("saved_treasures.txt");
            InputStreamReader inputStreamReader = new InputStreamReader(inPut);
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
            StringBuilder stringBuilder = new StringBuilder();

            while((toLoad = bufferedReader.readLine()) != null)
            {
                stringBuilder.append(toLoad + '\n');
            }

            textView.setText(stringBuilder.toString());

            textView.setVisibility(View.VISIBLE);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
