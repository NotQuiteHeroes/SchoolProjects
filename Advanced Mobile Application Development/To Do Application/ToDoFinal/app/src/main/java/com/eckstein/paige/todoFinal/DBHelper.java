package com.eckstein.paige.todoFinal;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.List;


public class DBHelper extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "toDoDB.db";
    private static final String TABLE_NAME = "tasks";
    private static final String TASK_COLUMN_ID = "id";
    private static final String TASK_COLUMN_NAME = "taskName";
    private static final String TASK_COLUMN_TYPE = "taskType";
    private static final String TASK_COLUMN_MINUTES = "taskMinutes";
    private static final String TASK_COLUMN_HOUR = "taskHour";
    private static final String TASK_COLUMN_MONTH = "taskMonth";
    private static final String TASK_COLUMN_DAY = "taskDay";
    private static final String TASK_COLUMN_YEAR = "taskYear";
    private HashMap hm;

    public DBHelper(Context context)
    {
        super(context, DATABASE_NAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db)
    {
        String CREATE_TABLE = "CREATE TABLE " + TABLE_NAME + "(" + TASK_COLUMN_ID + " INTEGER PRIMARY KEY," + TASK_COLUMN_NAME + " TEXT," + TASK_COLUMN_TYPE + " TEXT," + TASK_COLUMN_MINUTES + " INTEGER," + TASK_COLUMN_HOUR + " INTEGER," + TASK_COLUMN_MONTH + " INTEGER," + TASK_COLUMN_DAY + " INTEGER," + TASK_COLUMN_YEAR + " INTEGER" + ")";
        db.execSQL(CREATE_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion)
    {
        db.execSQL("DROP TABLE IF EXISTS tasks");
        onCreate(db);
    }

    public void insertTask(Task task)
    {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(TASK_COLUMN_NAME, task.getName());
        values.put(TASK_COLUMN_TYPE, task.getType());
        values.put(TASK_COLUMN_MINUTES, task.getMinutes());
        values.put(TASK_COLUMN_HOUR, task.getHour());
        values.put(TASK_COLUMN_MONTH, task.getMonth());
        values.put(TASK_COLUMN_DAY, task.getDay());
        values.put(TASK_COLUMN_YEAR, task.getYear());

        db.insert(TABLE_NAME, null, values);
        db.close();
    }

    Task getTask(int id)
    {
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.query(TABLE_NAME, new String[] { TASK_COLUMN_ID, TASK_COLUMN_NAME, TASK_COLUMN_TYPE, TASK_COLUMN_HOUR, TASK_COLUMN_MINUTES, TASK_COLUMN_MONTH, TASK_COLUMN_DAY, TASK_COLUMN_YEAR}, TASK_COLUMN_ID + "=?", new String[] {String.valueOf(id) }, null, null, null, null);

        if(cursor != null)
        {
            cursor.moveToFirst();
        }

        Task task = new Task(Integer.parseInt(cursor.getString(0)), cursor.getString(1), cursor.getString(2), Integer.parseInt(cursor.getString(3)), Integer.parseInt(cursor.getString(4)), Integer.parseInt(cursor.getString(5)), Integer.parseInt(cursor.getString(6)), Integer.parseInt(cursor.getString(7)));

        cursor.close();
        db.close();
        return task;
    }

    public ArrayList<Task> getAllTasks()
    {
        ArrayList<Task> taskList = new ArrayList<>();
        String select = "SELECT * FROM " + TABLE_NAME;

        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery(select, null);

        if(cursor.moveToFirst())
        {
            do {
                Task task = new Task();
                task.setID(Integer.parseInt(cursor.getString(0)));
                task.setName(cursor.getString(1));
                task.setType(cursor.getString(2));
                task.setMinutes(Integer.parseInt(cursor.getString(3)));
                task.setHour(Integer.parseInt(cursor.getString(4)));
                task.setMonth(Integer.parseInt(cursor.getString(5)));
                task.setDay(Integer.parseInt(cursor.getString(6)));
                task.setYear(Integer.parseInt(cursor.getString(7)));

                taskList.add(task);
            } while (cursor.moveToNext());
        }
        cursor.close();
        db.close();
        return taskList;
    }

    public ArrayList<Task> getTodayTasks()
    {
        //get current date information
        java.util.Date date = new Date();
        Calendar cal = Calendar.getInstance();
        cal.setTime(date);

        //Calendar.MONTH is 0 based, hence add one
        String month = Integer.toString(cal.get(Calendar.MONTH)+1);
        String day = Integer.toString(cal.get(Calendar.DAY_OF_MONTH));
        int year = cal.get(Calendar.YEAR);

        ArrayList<Task> taskList = new ArrayList<>();
        String select = "SELECT * FROM " + TABLE_NAME + " WHERE " + TASK_COLUMN_MONTH + " = "+month+" AND " + TASK_COLUMN_DAY + " = "+day;
        System.out.println(select);
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery(select, null);

        if(cursor.moveToFirst())
        {
            do {
                Task task = new Task();
                task.setID(Integer.parseInt(cursor.getString(0)));
                task.setName(cursor.getString(1));
                task.setType(cursor.getString(2));
                task.setMinutes(Integer.parseInt(cursor.getString(3)));
                task.setHour(Integer.parseInt(cursor.getString(4)));
                task.setMonth(Integer.parseInt(cursor.getString(5)));
                task.setDay(Integer.parseInt(cursor.getString(6)));
                task.setYear(Integer.parseInt(cursor.getString(7)));
                for(int i = 0; i < 8; i++)
                {
                    System.out.println(cursor.getString(i));
                }
                taskList.add(task);
            } while (cursor.moveToNext());
        }
        cursor.close();
        db.close();
        return taskList;
    }

    public int updateTask(Task task)
    {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(TASK_COLUMN_NAME, task.getName());
        values.put(TASK_COLUMN_TYPE, task.getType());
        values.put(TASK_COLUMN_MINUTES, task.getMinutes());
        values.put(TASK_COLUMN_HOUR, task.getHour());
        values.put(TASK_COLUMN_MONTH, task.getMonth());
        values.put(TASK_COLUMN_DAY, task.getDay());
        values.put(TASK_COLUMN_YEAR, task.getYear());

        return db.update(TABLE_NAME, values, TASK_COLUMN_ID + " =?", new String[] { String.valueOf(task.getID())});
    }

    public int getTaskCount()
    {
        String count = "SELECT * FROM " + TABLE_NAME;

        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery(count, null);
        int c = cursor.getCount();
        cursor.close();
        db.close();

        return c;
    }
}

