package com.eckstein.paige.todoShared;

import android.os.Parcelable;
import android.os.Parcel;

public class Task implements Parcelable {
    private String name;
    private String type;
    private int day;
    private int month;
    private int year;
    private int hour;
    private int minutes;

    //non-default constructor
    //requires all task information:
    //String task name and type(School, Personal, Work)
    //and int data for task date and time
    Task(String _name, String _type, int _day, int _month, int _year, int _hour, int _minutes)
    {
        name = _name;
        type = _type;
        day = _day;
        month = _month;
        year = _year;
        hour = _hour;
        minutes = _minutes;
    }

    Task()
    {}

    //for parcelable
    @Override
    public int describeContents()
    {
        return 0;
    }

    //for parcelable
    //object serialization occurs here
    @Override
    public void writeToParcel(Parcel dest, int flags)
    {
        dest.writeString(name);
        dest.writeString(type);
        dest.writeInt(day);
        dest.writeInt(month);
        dest.writeInt(year);
        dest.writeInt(hour);
        dest.writeInt(minutes);
    }

    //constructor for parcelable
    //invoked by createFromParcel
    //fields must be in same order as writeToParcel
    private Task(Parcel in)
    {
        this.name = in.readString();
        this.type = in.readString();
        this.day = in.readInt();
        this.month = in.readInt();
        this.year = in.readInt();
        this.hour = in.readInt();
        this.minutes = in.readInt();
    }

    //required for parcelable
    //used in deserialize an object
    public static final Parcelable.Creator<Task> CREATOR = new Parcelable.Creator<Task>()
    {
        @Override
        public Task createFromParcel(Parcel source)
        {
            return new Task(source);
        }

        @Override
        public Task[] newArray(int size)
        {
            return new Task[size];
        }
    };

    //standard getters beyond this point
    public String getName()
    {
        return name;
    }

    public String getType()
    {
        return type;
    }

    public int getDay()
    {
        return day;
    }

    public int getMonth()
    {
        return month;
    }

    public int getYear()
    {
        return year;
    }

    public int getHour()
    {
        return hour;
    }

    public int getMinutes()
    {
        return minutes;
    }
}
