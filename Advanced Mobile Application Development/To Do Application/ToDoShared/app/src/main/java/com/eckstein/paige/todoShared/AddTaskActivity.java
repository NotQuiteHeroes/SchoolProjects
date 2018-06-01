package com.eckstein.paige.todoShared;

import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

public class AddTaskActivity extends AppCompatActivity implements android.widget.AdapterView.OnItemSelectedListener{

    //for date and time selection
    android.app.DatePickerDialog datePicker;
    android.app.TimePickerDialog timePicker;

    //ui elements
    EditText taskNameField;
    Spinner taskSpinner;
    Button dateButton, timeButton;

    //values for task date and time
    int day, month, year;
    int minutes, hour;

    //values for task name and type
    String taskTypeString;
    String taskName;

    boolean saveData = false;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_task);

        taskNameField = findViewById(R.id.taskName);

        //task drop down menu
        taskSpinner = findViewById(R.id.taskType);
        android.widget.ArrayAdapter<CharSequence> adapter = android.widget.ArrayAdapter.createFromResource(this, R.array.task_types, R.layout.spinner);
        adapter.setDropDownViewResource(R.layout.spinner);
        taskSpinner.setOnItemSelectedListener(this);
        taskSpinner.setAdapter(adapter);

        saveData = false;

        dateButton =  findViewById(R.id.dateButton);

        //Date Picker functionality
        dateButton.setOnClickListener(new android.view.View.OnClickListener()
         {
            @Override
            public void onClick(android.view.View v)
            {
                final java.util.Calendar calendar = java.util.Calendar.getInstance();
                int mYear = calendar.get(java.util.Calendar.YEAR);
                int mMonth = calendar.get(java.util.Calendar.MONTH);
                int mDay = calendar.get(java.util.Calendar.DAY_OF_MONTH);

                datePicker = new android.app.DatePickerDialog(AddTaskActivity.this, new android.app.DatePickerDialog.OnDateSetListener() {
                    @Override
                    public void onDateSet(android.widget.DatePicker view, int pYear, int pMonth, int pDay)
                    {
                        String dateString = getString(R.string.dateFormatString, pMonth, pDay, pYear);
                        dateButton.setText(dateString);
                        day = pDay;
                        month = pMonth;
                        year = pYear;
                    }
                }, mYear, mMonth, mDay);
                datePicker.show();
            }
        });

        timeButton = findViewById(R.id.timeButton);

        //time picker functionality
        timeButton.setOnClickListener(new android.view.View.OnClickListener()
        {
            @Override
            public void onClick(android.view.View v)
            {
                final java.util.Calendar calendar = java.util.Calendar.getInstance();
                int mHour = calendar.get(java.util.Calendar.HOUR_OF_DAY);
                int mMinute = calendar.get(java.util.Calendar.MINUTE);

                timePicker = new android.app.TimePickerDialog(AddTaskActivity.this, new android.app.TimePickerDialog.OnTimeSetListener()
                {
                    @Override
                    public void onTimeSet(android.widget.TimePicker view, int pHour, int pMinute)
                    {
                        String timeString = getString(R.string.timeFormatString, pHour, pMinute);
                        timeButton.setText(timeString);
                        hour = pHour;
                        minutes = pMinute;
                    }
                }, mHour, mMinute, false);
                timePicker.show();
            }
        });

        save();

        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
        if(prefs.getBoolean("isSaved", false))
        {
            load();
        }

        //add task button
        android.widget.Button addTaskButton = findViewById(R.id.addTaskButton);
        addTaskButton.setOnClickListener(new android.view.View.OnClickListener()
        {
            @Override
            public void onClick(android.view.View view)
            {
                taskName = taskNameField.getText().toString();

                Task task = new Task(taskName, taskTypeString, day, month, year, hour, minutes);
                android.content.Intent taskData = new android.content.Intent(AddTaskActivity.this, MainActivity.class);
                taskData.putExtra("task", task);
                setResult(RESULT_OK, taskData);
                finish();
            }
        });
    }

    public void save()
    {
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
        SharedPreferences.Editor edit = prefs.edit();

        saveData = true;

        taskName = taskNameField.getText().toString();

        //clear out old data
        edit.remove("taskName");
        edit.remove("taskType");
        edit.remove("day");
        edit.remove("month");
        edit.remove("year");
        edit.remove("hour");
        edit.remove("minutes");
        edit.remove("isSaved");

        //add new data
        edit.putString("taskName", taskName);
        edit.putString("taskType", taskTypeString);
        edit.putInt("day", day);
        edit.putInt("month", month);
        edit.putInt("year", year);
        edit.putInt("hour", hour);
        edit.putInt("minutes", minutes);
        edit.putBoolean("isSaved", saveData);

        edit.commit();
    }

    public void load()
    {
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);

        taskName = prefs.getString("taskName", null);
        taskTypeString = prefs.getString("taskType", null);
        day = prefs.getInt("day", 1);
        month = prefs.getInt("month", 1);
        year = prefs.getInt("year", 2018);
        hour = prefs.getInt("hour", 12);
        minutes = prefs.getInt("minutes", 0);

        taskNameField.setText(taskName);
        taskSpinner.setSelection(getIndex(taskSpinner, taskTypeString));
        dateButton.setText(getString(R.string.dateFormatString, month, day, year));
        timeButton.setText(getString(R.string.timeFormatString, hour, minutes));
    }

    private int getIndex(Spinner spin, String value)
    {
        int index = 0;

        for(int i = 0; i < spin.getCount(); i++)
        {
            if(spin.getItemAtPosition(i).toString().equalsIgnoreCase(value))
            {
                index = i;
                break;
            }
        }
        return index;
    }

    @Override
    public void onItemSelected(android.widget.AdapterView<?> parent, android.view.View view, int position, long id)
    {
        taskTypeString = parent.getItemAtPosition(position).toString();
    }

    @Override
    public void onNothingSelected(android.widget.AdapterView<?> arg0)
    {
    }

}


