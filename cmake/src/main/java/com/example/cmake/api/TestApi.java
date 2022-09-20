package com.example.cmake.api;

import com.example.cmake.bean.User;

/**
 * Desc:
 *
 * @author Coco
 * Created on 2022/9/19 21:24
 * Email:
 */
public class TestApi {
    static {
        System.loadLibrary("test");
    }
    public native User test();
}
