package mobile.rasmussen.edu.geocache;

import android.content.Intent;
import android.provider.ContactsContract;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

public class ProfileActivity extends AppCompatActivity {

    TextView solvedView;
    Button homeButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);

        solvedView = (TextView) findViewById(R.id.solvedView);

        homeButton = (Button) findViewById(R.id.profileHome);
        homeButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                startActivity(new Intent(ProfileActivity.this, MainActivity.class));
            }
        });

        solvedView.append("Points: \n");
        solvedView.append(String.valueOf(TreasureActivity.points) + "\n");

        solvedView.append("Solved: \n");

        if(TreasureActivity.shawSolved == true){
            solvedView.append("Shaw's Bard \n");
        }
        if(TreasureActivity.wildSolved == true){
            solvedView.append("Into the Wild \n");
        }
        if(TreasureActivity.sleeplessSolved == true){
            solvedView.append("The Sleepless \n");
        }
        if(TreasureActivity.songBirdsSolved == true){
            solvedView.append("Songbirds \n");
        }
        if(TreasureActivity.fruitSolved == true){
            solvedView.append("Fresh Fruit \n");
        }
    }
}
