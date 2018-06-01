package com.eckstein.paige.todoFinal;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

import java.util.ArrayList;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    ArrayList<Task> currentTasks = new ArrayList<>();
    DBHelper db = new DBHelper(this);

    //all tasks layout
    android.widget.LinearLayout personalParent;
    android.widget.LinearLayout workParent;
    android.widget.LinearLayout schoolParent;

    android.widget.ScrollView personalScroll;
    android.widget.ScrollView workScroll;
    android.widget.ScrollView schoolScroll;

    //today tasks layout
    android.widget.LinearLayout personalTodayParent;
    android.widget.LinearLayout workTodayParent;
    android.widget.LinearLayout schoolTodayParent;

    android.widget.ScrollView personalTodayScroll;
    android.widget.ScrollView workTodayScroll;
    android.widget.ScrollView schoolTodayScroll;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        personalParent = findViewById(R.id.personalLinear);
        workParent = findViewById(R.id.workLinear);
        schoolParent = findViewById(R.id.schoolLinear);

        personalScroll = findViewById(R.id.personalScroll);
        workScroll = findViewById(R.id.workScroll);
        schoolScroll = findViewById(R.id.schoolScroll);

        //today tasks layout
        personalTodayParent = findViewById(R.id.personalTodayLinear);
        workTodayParent = findViewById(R.id.workTodayLinear);
        schoolTodayParent = findViewById(R.id.schoolTodayLinear);

        personalTodayScroll = findViewById(R.id.personalTodayScroll);
        workTodayScroll = findViewById(R.id.workTodayScroll);
        schoolTodayScroll = findViewById(R.id.schoolTodayScroll);

        ArrayList<Task> tasks = db.getAllTasks();

        for(Task task : tasks)
        {
            createCheckbox(task, false);
        }

        final Button todayButton = findViewById(R.id.todayButton);
        final Button allButton = findViewById(R.id.allButton);

        allButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                workParent.setVisibility(View.VISIBLE);
                workScroll.setVisibility(View.VISIBLE);
                personalParent.setVisibility(View.VISIBLE);
                personalScroll.setVisibility(View.VISIBLE);
                schoolParent.setVisibility(View.VISIBLE);
                schoolScroll.setVisibility(View.VISIBLE);

                workTodayParent.setVisibility(View.INVISIBLE);
                workTodayScroll.setVisibility(View.INVISIBLE);
                personalTodayParent.setVisibility(View.INVISIBLE);
                personalTodayScroll.setVisibility(View.INVISIBLE);
                schoolTodayParent.setVisibility(View.INVISIBLE);
                schoolTodayScroll.setVisibility(View.INVISIBLE);


                todayButton.setVisibility(View.VISIBLE);
                allButton.setVisibility(View.INVISIBLE);

                workParent.removeAllViews();
                personalParent.removeAllViews();
                schoolParent.removeAllViews();

                ArrayList<Task> tasks = db.getAllTasks();

                for(Task task: tasks)
                {
                    createCheckbox(task, false);
                }
            }
        });

        //view today's tasks only
        todayButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                workParent.setVisibility(View.INVISIBLE);
                workScroll.setVisibility(View.INVISIBLE);
                personalParent.setVisibility(View.INVISIBLE);
                personalScroll.setVisibility(View.INVISIBLE);
                schoolParent.setVisibility(View.INVISIBLE);
                schoolScroll.setVisibility(View.INVISIBLE);

                workTodayParent.setVisibility(View.VISIBLE);
                workTodayScroll.setVisibility(View.VISIBLE);
                personalTodayParent.setVisibility(View.VISIBLE);
                personalTodayScroll.setVisibility(View.VISIBLE);
                schoolTodayParent.setVisibility(View.VISIBLE);
                schoolTodayScroll.setVisibility(View.VISIBLE);

                todayButton.setVisibility(View.INVISIBLE);
                allButton.setVisibility(View.VISIBLE);

                workTodayParent.removeAllViews();
                personalTodayParent.removeAllViews();
                schoolTodayParent.removeAllViews();

                ArrayList<Task> tasks = db.getTodayTasks();

                for(Task task: tasks)
                {
                    System.out.println(task.getName());
                    createCheckbox(task, true);
                }
            }
        });


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
                  db.insertTask(task);
                  currentTasks.add(task);
                  createCheckbox(task, false);
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
                createCheckbox(task, false);
            }
        }
    }

    public void createCheckbox(Task task, boolean today)
    {
        int month = getCurrentMonth();
        int day = getCurrentDay();
        int year = getCurrentYear();

        android.widget.CheckBox checkBox = new android.widget.CheckBox(this);

        //get task date information
        int taskMonth = task.getMonth();
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

        String taskType = task.getType();

        if(!today) {
            //add checkbox to appropriate section
            if (taskType.equals("Personal")) {
                personalParent.addView(checkBox);
            } else if (taskType.equals("Work")) {
                workParent.addView(checkBox);
            } else if (taskType.equals("School")) {
                schoolParent.addView(checkBox);
            }
        }

        if(today)
        {
            if (taskType.equals("Personal")) {
                personalTodayParent.addView(checkBox);
            } else if (taskType.equals("Work")) {
                workTodayParent.addView(checkBox);
            } else if (taskType.equals("School")) {
                schoolTodayParent.addView(checkBox);
            }
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
