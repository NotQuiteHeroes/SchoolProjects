package com.eckstein.paige.todoFinal;

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
    private int ID;

    //non-default constructor
    //requires all task information:
    //String task name and type(School, Personal, Work)
    //and int data for task date and time
    Task(int _ID, String _name, String _type, int _minutes, int _hour, int _month, int _day, int _year)
    {
        name = _name;
        type = _type;
        day = _day;
        month = _month;
        year = _year;
        hour = _hour;
        minutes = _minutes;
        ID = _ID;
    }

    Task(String _name, String _type, int _minutes, int _hour, int _month, int _day, int _year)
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
        dest.writeInt(ID);
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
        this.ID = in.readInt();
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
    public int getID() { return ID; }

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



    //standard setters beyond this point
    public void setID(int ID)
    {
        this.ID = ID;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setType(String type)
    {
        this.type = type;
    }

    public void setDay(int day)
    {
        this.day = day;
    }

    public void setMonth(int month)
    {
        this.month = month;
    }

    public void setYear(int year)
    {
        this.year = year;
    }

    public void setHour(int hour)
    {
        this.hour = hour;
    }

    public void setMinutes(int minutes)
    {
        this.minutes = minutes;
    }
}
