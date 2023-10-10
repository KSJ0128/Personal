package com.cookandroid.hw1_5_20201028

import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.ImageView
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        lateinit var editText: EditText
        lateinit var btn1: Button
        lateinit var btn2: Button
        lateinit var radioGroup: RadioGroup
        lateinit var radioBtn1: RadioButton
        lateinit var radioBtn2: RadioButton
        lateinit var img: ImageView

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText = findViewById<EditText>(R.id.editText)
        btn1 = findViewById<Button>(R.id.button1)
        btn1.setOnClickListener {
            Toast.makeText(applicationContext, editText.text.toString(), Toast.LENGTH_SHORT).show()
        }
        btn2 = findViewById<Button>(R.id.button2)
        btn2.setOnClickListener {
            val webpage = Uri.parse(editText.text.toString())
            val intent = Intent(Intent.ACTION_VIEW, webpage)
            startActivity(intent)
        }
        radioGroup = findViewById<RadioGroup>(R.id.radioGroup)
        radioBtn1 = findViewById<RadioButton>(R.id.radioButton1)
        radioBtn2 = findViewById<RadioButton>(R.id.radioButton2)
        img = findViewById<ImageView>(R.id.imageView1)
        radioGroup.setOnCheckedChangeListener{ group, checkedId ->
            when(checkedId) {
                R.id.radioButton1 -> {
                    // 라디오 버튼 1을 클릭했을 때 이미지 변경
                    img.setImageResource(R.drawable.oreo)
                }
                R.id.radioButton2 -> {
                    // 라디오 버튼 2를 클릭했을 때 이미지 변경
                    img.setImageResource(R.drawable.pie)
                }
            }
        }
        getSupportActionBar()?.setDisplayShowHomeEnabled(true)
        getSupportActionBar()?.setIcon(R.drawable.ic_launcher)
    }
}