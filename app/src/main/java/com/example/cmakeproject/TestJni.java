package com.example.cmakeproject;

/**
 * Desc:
 *
 * @author Coco
 * Created on 2022/9/17 22:21
 * Email:
 */
public class TestJni {
    static {
        System.loadLibrary("test");
    }

    public native int setResponse();

    public native int setPerson();
}
