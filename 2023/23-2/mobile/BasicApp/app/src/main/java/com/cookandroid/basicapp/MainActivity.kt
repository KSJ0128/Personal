package com.cookandroid.basicapp

import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    lateinit var button1: Button
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        button1 = findViewById<Button>(R.id.button1)
        button1.setOnClickListener {
            Toast.makeText(applicationContext, "버튼을 눌렀어요", Toast.LENGTH_SHORT).show()
        }
    }
}