package com.eckstein.paige.todoBundle;

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

    @Override
    public void onSaveInstanceState(Bundle out)
    {
        taskName = taskNameField.getText().toString();
        out.putString("taskName", taskName);
        out.putString("taskType", taskTypeString);
        out.putInt("day", day);
        out.putInt("month", month);
        out.putInt("year", year);
        out.putInt("hour", hour);
        out.putInt("minutes", minutes);

        super.onSaveInstanceState(out);
    }

    @Override
    public void onRestoreInstanceState(Bundle save)
    {
        super.onRestoreInstanceState(save);

        taskName = save.getString("taskName");
        taskTypeString = save.getString("taskType");
        day = save.getInt("day");
        month = save.getInt("month");
        year = save.getInt("year");
        hour = save.getInt("hour");
        minutes = save.getInt("minutes");

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


