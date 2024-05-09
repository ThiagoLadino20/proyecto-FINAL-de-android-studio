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
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;
import java.util.Map;

public class register extends AppCompatActivity {

    private EditText mEditTextName;
    private EditText mEditTextEmail;
    private EditText mEditTextPassword;
    private Button mButtonRegister;

    // VARAIBELS DE LOS DATOS QUE VAMOS A REGISTRAR DEL USUARIO

    private String name = "";
    private String email = "";
    private String password = "";

    //OBJETO QUE HACE LA ACCION DE REGISTRAR (OOSEA, YA APLICA FIREBASE)

    FirebaseAuth mAuth;
    DatabaseReference mDatabase;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_register);


        mAuth = FirebaseAuth.getInstance();
        mDatabase = FirebaseDatabase.getInstance().getReference();

        mEditTextName = (EditText) findViewById(R.id.editTextName);
        mEditTextEmail = (EditText) findViewById(R.id.editTextEmail);
        mEditTextPassword = (EditText) findViewById(R.id.editTextPassword);
        mButtonRegister = (Button) findViewById(R.id.btnRgister);

        mButtonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                name = mEditTextName.getText().toString();
                email = mEditTextEmail.getText().toString();
                password = mEditTextPassword.getText().toString();

                if(!name.isEmpty() && !email.isEmpty() && !password.isEmpty()){
                    if(password.length() >= 6){
                        registerUser();
                    } else {
                        Toast.makeText(getApplicationContext(), "La contraseña debe tener al menos 6 caracteres", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(getApplicationContext(), "Debe de llenar todos los campos", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void registerUser() {
        mAuth.createUserWithEmailAndPassword(email, password).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()){
                    Map<String, Object> map = new HashMap<>();
                    map.put("name", name);
                    map.put("email", email);
                    map.put("password", password);

                    String id = mAuth.getCurrentUser().getUid();

                    mDatabase.child("users").child(id).setValue(map).addOnCompleteListener(new OnCompleteListener<Void>() {
                        @Override
                        public void onComplete(@NonNull Task<Void> task2) {
                            if(task2.isSuccessful()){
                                startActivity(new Intent(register.this, user.class));
                                finish();
                            } else {
                                Toast.makeText(getApplicationContext(), "No se pudieron crear los datos correctamente, por favor intente de nuevo registrar el usuario", Toast.LENGTH_SHORT).show();
                            }
                        }
                    });
                } else {
                    Toast.makeText(getApplicationContext(), "No se pudo registrar el usuario", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }


    @Override
    protected void onStart() {
        super.onStart();
        if(mAuth.getCurrentUser() != null){
            startActivity(new Intent(register.this, user.class));
            finish();
        }
    }
}