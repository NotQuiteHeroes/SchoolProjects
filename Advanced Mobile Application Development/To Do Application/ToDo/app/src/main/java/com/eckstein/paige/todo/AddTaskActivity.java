package com.eckstein.paige.todo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class AddTaskActivity extends AppCompatActivity implements android.widget.AdapterView.OnItemSelectedListener{

    android.app.DatePickerDialog datePicker;
    android.app.TimePickerDialog timePicker;

    int day, month, year;
    int minutes, hour;

    String taskTypeString;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_task);

        final android.widget.EditText taskNameField = findViewById(R.id.taskName);

        //task drop down menu
        android.widget.Spinner taskSpinner = findViewById(R.id.taskType);
        android.widget.ArrayAdapter<CharSequence> adapter = android.widget.ArrayAdapter.createFromResource(this, R.array.task_types, R.layout.spinner);
        adapter.setDropDownViewResource(R.layout.spinner);
        taskSpinner.setOnItemSelectedListener(this);
        taskSpinner.setAdapter(adapter);

        final android.widget.Button dateButton =  findViewById(R.id.dateButton);

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

        final android.widget.Button timeButton = findViewById(R.id.timeButton);

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
                String taskName = taskNameField.getText().toString();

                android.content.Intent taskData = new android.content.Intent(AddTaskActivity.this, MainActivity.class);
                taskData.putExtra("day", day);
                taskData.putExtra("month", month);
                taskData.putExtra("year", year);
                taskData.putExtra("hour", hour);
                taskData.putExtra("minutes", minutes);
                taskData.putExtra("taskName", taskName);
                taskData.putExtra("taskType", taskTypeString);
                setResult(RESULT_OK, taskData);
                finish();
            }
        });
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


