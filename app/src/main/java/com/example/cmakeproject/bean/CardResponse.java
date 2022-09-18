package com.example.cmakeproject.bean;

import android.util.Log;

/**
 * Desc:
 *
 * @author Coco
 * Created on 2022/9/17 22:27
 * Email:
 */
public class CardResponse {

    private static final String TAG = "TAG";
    public byte[] command;

    public static int commandLen;

    public Person person;

    public void setPerson(Person person) {
        Log.d(TAG, "C++ 调用了 setPerson()");
        this.person = person;
    }

    public Person getPerson(){
        return person;
    }
}
