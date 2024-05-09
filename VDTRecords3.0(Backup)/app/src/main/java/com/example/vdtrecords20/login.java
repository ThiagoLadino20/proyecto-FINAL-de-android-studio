package com.example.vdtrecords20;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class login extends AppCompatActivity {

    private EditText mEditTextEmail;
    private EditText mEditTextPassword;
    private Button mButtonLogin;

    private String email ="";
    private String password = "";


    private FirebaseAuth mAuth;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_login);

        mAuth = FirebaseAuth.getInstance();

        mEditTextEmail = (EditText) findViewById(R.id.editTextEmail);
        mEditTextPassword = (EditText) findViewById(R.id.editTextPassword);
        mButtonLogin = (Button) findViewById(R.id.btnLogin);

        mButtonLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                email = mEditTextEmail.getText().toString();
                password = mEditTextPassword.getText().toString();


                if (!email.isEmpty() && !password.isEmpty()) {
                    loginUser();
                }
                else {
                    Toast.makeText(login.this, "Complete los campos", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }

    private void loginUser() {

        mAuth.signInWithEmailAndPassword(email, password).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if(task.isSuccessful()){
                    startActivity(new Intent(login.this, user.class));
                    finish();
                }else{
                    Toast.makeText(login.this, "Error al iniciar sesion", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }
}