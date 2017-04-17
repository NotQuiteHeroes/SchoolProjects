package mobile.rasmussen.edu.geocache;


import android.content.Intent;
import android.content.res.Resources;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class TreasureActivity extends AppCompatActivity {

    boolean hint1Used;
    boolean hint2Used;

    public static boolean shawSolved;
    public static boolean wildSolved;
    public static boolean sleeplessSolved;
    public static boolean songBirdsSolved;
    public static boolean fruitSolved;

    public static int points;

    double userLong = PlayActivity.longitude;
    double userLat = PlayActivity.latitude;

    TextView treasureName;
    TextView hintView;
    TextView pointsView;

    EditText userWhereEdit;
    EditText userWhatEdit;

    Button submitButton;
    Button hintButton;
    Button homeButton;
    Button textButton;

    double treasureLong;
    double treasureLat;

    String message;

    String hint1 = "", hint2 = "", answerWhat = "", answerWhere = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_treasure);

        //get treasure selection from bundle
        Bundle b = getIntent().getExtras();
        int id = b.getInt("TreasureType");

        treasureName = (TextView) findViewById(R.id.TreasureTitle);
        hintView = (TextView) findViewById(R.id.Hint);
        pointsView = (TextView) findViewById(R.id.PointsView);

        Resources res = getResources();
        String tempPoints = String.format(res.getString(R.string.StringPoints), points);
        pointsView.setText(tempPoints);

        userWhereEdit = (EditText) findViewById(R.id.AnswerWhere);
        userWhatEdit = (EditText) findViewById(R.id.AnswerWhat);

        submitButton = (Button) findViewById(R.id.ButtonSubmit);
        hintButton = (Button) findViewById(R.id.ButtonHint);

        homeButton = (Button) findViewById(R.id.ButtonHome);
        homeButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(TreasureActivity.this, MainActivity.class));
            }
        });

        textButton = (Button) findViewById(R.id.textMe);
        textButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                sendText();
            }
        });

        //set variables based on selected treasure from Play Screen
        switch(id){
            case 1:
                treasureName.setText(getString(R.string.StringShaw));
                hintView.setText(getString(R.string.ShawDescription));
                hint1 = getString(R.string.ShawHint1);
                hint2 = getString(R.string.ShawHint2);
                //currently case sensitive
                answerWhat = "Shakespeare's Bust";
                answerWhere = "Tower Grove Park";
                //set to 0.0 for testing purposes
                treasureLong = 0.0; //actual long: -90.26
                treasureLat = 0.0; //actual lat: 38.60
                message = getString(R.string.shawMessage);
                break;
            case 2:
                treasureName.setText(getString(R.string.StringWild));
                hintView.setText(getString(R.string.WildDescription));
                hint1 = getString(R.string.WildHint1);
                hint2 = getString(R.string.WildHint2);
                answerWhat = "Phil's Statue";
                answerWhere = "St. Louis Zoo";
                //set to 0.0 for testing purposes
                treasureLong = 0.0; //actual long: -90.28
                treasureLat = 0.0; //actual lat: 38.63
                message = getString(R.string.wildMessage);
                break;
            case 3:
                treasureName.setText(getString(R.string.StringSleepless));
                hintView.setText(getString(R.string.SleeplessDescription));
                hint1 = getString(R.string.SleeplessHint1);
                hint2 = getString(R.string.SleeplessHint2);
                answerWhat = "Clark's Mausoleum";
                answerWhere = "Bellefontaine Cemetery";
                //set to 0.0 for testing purposes
                treasureLong = 0.0;  //actual long: -90.23
                treasureLat = 0.0; //actual lat: 38.69
                message = getString(R.string.sleeplessMessage);
                break;
            case 4:
                treasureName.setText(getString(R.string.StringSongbird));
                hintView.setText(getString(R.string.SongBirdDescription));
                hint1 = getString(R.string.SongBirdHint1);
                hint2 = getString(R.string.SongBirdHint2);
                answerWhat = "Stan the Man's Statue";
                answerWhere = "Busch Stadium";
                //set to 0.0 for testing purposes
                treasureLong = 0.0; //actual long: -90.19
                treasureLat = 0.0; //actual lat: 38.62
                message = getString(R.string.songBirdMessage);
                break;
            case 5:
                treasureName.setText(getString(R.string.StringFruit));
                hintView.setText(getString(R.string.FruitDescription));
                hint1 = getString(R.string.FruitHint1);
                hint2 = getString(R.string.FruitHint2);
                answerWhat = "The Duck Room";
                answerWhere = "Blueberry Hill";
                //set to 0.0 for testing purposes
                treasureLong = 0.0; //actual long: -90.30
                treasureLat = 0.0; //actual lat: 38.65
                message = getString(R.string.fruitMessage);
                break;
            default:
                finish();
        }

        submitButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                //get users answers upon clicking submit button
                String userWhere = userWhereEdit.getText().toString();
                String userWhat = userWhatEdit.getText().toString();

                if ((userWhere.equals(answerWhere) && userWhat.equals(answerWhat)) && (userLong == treasureLong && userLat == treasureLat))
                {
                    if(answerWhere.equals("Tower Grove Park")){
                        shawSolved = true;
                    }
                    else if(answerWhere.equals("St. Louis Zoo")){
                        wildSolved = true;
                    }
                    else if(answerWhere.equals("Bellefontaine Cemetery")){
                        sleeplessSolved = true;
                    }
                    else if(answerWhere.equals("Busch Stadium")){
                        songBirdsSolved = true;
                    }
                    else if(answerWhere.equals("Blueberry Hill")){
                        fruitSolved = true;
                    }
                    Toast.makeText(TreasureActivity.this, "Correct!", Toast.LENGTH_SHORT).show();
                    if(!hint1Used && !hint2Used){
                        points += 10;
                    }
                    else if(hint1Used && !hint2Used){
                        points += 5;
                    }
                    else if(hint1Used && hint2Used){
                        points += 1;
                    }

                    finish();
                }
                else {
                    Toast.makeText(TreasureActivity.this, "Incorrect!", Toast.LENGTH_SHORT).show();
                    userWhereEdit.setText("");
                    userWhatEdit.setText("");
                }
            }
        });

        hintButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                if(hint1Used && hint2Used)
                {
                    hintView.append("End.");
                }
                else if(!hint1Used)
                {
                    hintView.append("\n");
                    hintView.append(hint1);
                    hint1Used = true;
                }
                else if(!hint2Used)
                {
                    hintView.append("\n");
                    hintView.append(hint2);
                    hint2Used = true;
                }
            }
        });
    }

    private void sendText()
    {
        TelephonyManager telephonyManager = (TelephonyManager) getSystemService(TELEPHONY_SERVICE);
        String userNumber = telephonyManager.getLine1Number();

        SmsManager smsManager = SmsManager.getDefault();
        smsManager.sendTextMessage(userNumber, null, message, null, null);
        Toast.makeText(getApplicationContext(), "Text sent.", Toast.LENGTH_SHORT).show();
    }
}
