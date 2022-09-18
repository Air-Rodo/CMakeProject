package com.example.cmakeproject;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.example.cmakeproject.bean.CardResponse;
import com.example.cmakeproject.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "TAG";
    private ActivityMainBinding binding;
    private TestJni testJni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        testJni = new TestJni();
        initListener();
    }

    private void initListener() {
        binding.sampleTest1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                testJni.setResponse();
                Log.d(TAG, "commandLen:" + CardResponse.commandLen);
            }
        });
        binding.sampleTest2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                testJni.setPerson();
                Log.d(TAG, "person:" + new CardResponse().getPerson());
            }
        });
    }
}