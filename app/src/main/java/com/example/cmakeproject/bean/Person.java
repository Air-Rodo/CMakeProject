package com.example.cmakeproject.bean;

/**
 * Desc:
 *
 * @author Coco
 * Created on 2022/9/18 23:36
 * Email:
 */
public class Person {
    public String username;

    public int password;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public int getPassword() {
        return password;
    }

    public void setPassword(int password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "Person{" +
                "username='" + username + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
