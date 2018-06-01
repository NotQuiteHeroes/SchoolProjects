package com.eckstein.paige.todo;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                android.content.Intent intent = new android.content.Intent(view.getContext(), AddTaskActivity.class);
                startActivityForResult(intent, 1);
            }
        });
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, android.content.Intent data)
    {
        //sections to add checkboxes to
        android.widget.LinearLayout personalParent = findViewById(R.id.personalLinear);
        android.widget.LinearLayout workParent = findViewById(R.id.workLinear);
        android.widget.LinearLayout schoolParent = findViewById(R.id.schoolLinear);

        //get current date
        java.util.Date date = new java.util.Date();
        java.util.Calendar calendar = java.util.Calendar.getInstance();
        calendar.setTime(date);

        int month = calendar.get(java.util.Calendar.MONTH)+1;
        int day = calendar.get(java.util.Calendar.DAY_OF_MONTH);
        int year = calendar.get(java.util.Calendar.YEAR);

        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 1)
        {
          if(resultCode == RESULT_OK)
          {
              android.widget.CheckBox checkBox = new android.widget.CheckBox(this);

              //get task date information
              int taskMonth = data.getIntExtra("month", 1) + 1;
              int taskDay = data.getIntExtra("day", 1);
              int taskYear = data.getIntExtra("year", 2018);

              //if task date is current date, display time of task
              if(month == taskMonth && day == taskDay && year == taskYear)
              {
                  String taskFormat = getString(R.string.hourTaskFormatString, data.getStringExtra("taskName"), data.getIntExtra("hour", 12), data.getIntExtra("minutes", 00));
                  checkBox.setText(taskFormat);
              }
              //otherwise, add task with full date
              else
              {
                  String taskFormat = getString(R.string.dateTaskFormatString, data.getStringExtra("taskName"), taskMonth, taskDay, taskYear);
                  checkBox.setText(taskFormat);
              }

              //add checkbox to appropriate section
              String taskType = data.getStringExtra("taskType");
              if(taskType.equals("Personal"))
              {
                 personalParent.addView(checkBox);
              }
              else if(taskType.equals("Work"))
              {
                  workParent.addView(checkBox);
              }
              else if(taskType.equals("School"))
              {
                  schoolParent.addView(checkBox);
              }
          }
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
