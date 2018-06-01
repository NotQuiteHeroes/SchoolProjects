package com.eckstein.paige.todoBundle;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

import java.util.ArrayList;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    ArrayList<Task> currentTasks = new ArrayList<>();

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
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 1)
        {
          if(resultCode == RESULT_OK)
          {
              Bundle bundle = data.getExtras();
              if(bundle != null)
              {
                  Task task = bundle.getParcelable("task");
                  currentTasks.add(task);
                  createCheckbox(task);
              }
          }
        }
    }

    @Override
    public void onSaveInstanceState(Bundle out)
    {
        out.putParcelableArrayList("currentTasks", currentTasks);
        super.onSaveInstanceState(out);
    }

    @Override
    public void onRestoreInstanceState(Bundle save)
    {
        super.onRestoreInstanceState(save);
        if(save != null)
        {
            currentTasks = save.getParcelableArrayList("currentTasks");
            for (Task task : currentTasks)
            {
                createCheckbox(task);
            }
        }
    }

    public void createCheckbox(Task task)
    {
        //sections to add checkboxes to
        android.widget.LinearLayout personalParent = findViewById(R.id.personalLinear);
        android.widget.LinearLayout workParent = findViewById(R.id.workLinear);
        android.widget.LinearLayout schoolParent = findViewById(R.id.schoolLinear);

        int month = getCurrentMonth();
        int day = getCurrentDay();
        int year = getCurrentYear();

        android.widget.CheckBox checkBox = new android.widget.CheckBox(this);

        //get task date information
        int taskMonth = task.getMonth() + 1;
        int taskDay = task.getDay();
        int taskYear = task.getYear();

        //if task date is current date, display time of task
        if(month == taskMonth && day == taskDay && year == taskYear)
        {
            String taskFormat = getString(R.string.hourTaskFormatString, task.getName(), task.getHour(), task.getMinutes());
            checkBox.setText(taskFormat);
        }
        //otherwise, add task with full date
        else
        {
            String taskFormat = getString(R.string.dateTaskFormatString, task.getName(), taskMonth, taskDay, taskYear);
            checkBox.setText(taskFormat);
        }

        //add checkbox to appropriate section
        String taskType = task.getType();
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

    public int getCurrentMonth()
    {
        Calendar calendar = getCalendar();
        return(calendar.get(java.util.Calendar.MONTH)+1);
    }

    public int getCurrentDay()
    {
        Calendar calendar = getCalendar();
        return(calendar.get(java.util.Calendar.DAY_OF_MONTH));
    }

    public int getCurrentYear()
    {
        Calendar calendar = getCalendar();
        return(calendar.get(java.util.Calendar.YEAR));
    }

    public Calendar getCalendar()
    {
        //get current date
        return(java.util.Calendar.getInstance());
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
