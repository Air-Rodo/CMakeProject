package com.example.cmakeproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import com.example.cmake.api.TestApi;
import com.example.cmake.bean.User;
import com.example.cmakeproject.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "TAG";
    private ActivityMainBinding binding;

    private TestApi api;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        initListener();
    }

    private void initListener() {
        api = new TestApi();
        binding.sampleTest1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                User test = api.test();
                Log.d(TAG, "user:" + test);
            }
        });
        binding.sampleTest2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

            }
        });
    }
}