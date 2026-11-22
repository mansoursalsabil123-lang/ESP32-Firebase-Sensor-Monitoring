
/**
 * Created by K. Suwatchai (Mobizt)
 *
 * Email: k_suwatchai@hotmail.com
 *
 * Github: https://github.com/mobizt/Firebase-ESP32
 *
 * Copyright (c) 2023 mobizt
 *
 */


#include <WiFi.h>
#include <FirebaseESP32.h>

// Provide the token generation process info.
#include <addons/TokenHelper.h>
// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "EPI-STUDENTS"
#define WIFI_PASSWORD "epietud2027"


// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyCClnfvXkzhsh9CNjcxaeA7SCKVlUHWwIU"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://esp32-e1beb-default-rtdb.europe-west1.firebasedatabase.app/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "esp32dev@gmail.com"
#define USER_PASSWORD "123456"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

const int ledpin=37;
const int captpin=9;

void setup()
{
  pinMode(ledpin,OUTPUT);
  pinMode(captpin,INPUT);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

 
  Firebase.begin(&config, &auth);

  // Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  
}

void loop()
{




int val=analogRead(captpin);
 Firebase.setInt(fbdo, F("/capteur"), val); 
int ledvalue;
Firebase.getInt(fbdo, F("/led"), &ledvalue); 
digitalWrite(ledpin,ledvalue);
delay(1000);
  }
