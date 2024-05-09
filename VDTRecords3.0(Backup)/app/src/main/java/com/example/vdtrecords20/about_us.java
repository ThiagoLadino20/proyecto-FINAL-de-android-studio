package com.example.vdtrecords20;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class about_us extends AppCompatActivity {

    private ImageView imgInfoPopup;
    private TextView txtThiago;
    private TextView txtJuanda;
    private TextView txtVale;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_about_us);

        imgInfoPopup = findViewById(R.id.imgInfoPopup);
        txtThiago = findViewById(R.id.txtPopupThiago);
        txtJuanda = findViewById(R.id.txtPopupJuanda);
        txtVale = findViewById(R.id.txtPopupVal);

        imgInfoPopup.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {

            }
        });


        txtThiago.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(about_us.this, popup_thiago.class));

            }
        });


        txtJuanda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(about_us.this, popup_juanda.class));

            }
        });

        txtVale.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(about_us.this, popup_val.class));

            }
        });
    }
}