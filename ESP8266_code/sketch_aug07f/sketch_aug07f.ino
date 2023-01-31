#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
     



 

#define FIREBASE_HOST "Your FireBase Host"
#define FIREBASE_AUTH "Your FireBase Authentication Key"
#define WIFI_SSID " " //provide ssid (wifi name)
#define WIFI_PASSWORD " " //wifi password
void setup()
{ 
 

 Serial.begin(9600);
 pinMode(D7,OUTPUT);
 pinMode(D6,OUTPUT);
 pinMode(D5,OUTPUT);
 pinMode(D4,OUTPUT);
 pinMode(D3,OUTPUT);
 pinMode(D1,OUTPUT);
 pinMode(D8, INPUT);

 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("connecting");
 while (WiFi.status() != WL_CONNECTED)
 {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.print("connected: ");
 Serial.println(WiFi.localIP());
 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}
 
void loop()
{
//read the status of each notifier from the data base and take corresponding action
String value_1 = Firebase.getString("person1"); 
String value_2 = Firebase.getString("person2");
String value_3 = Firebase.getString("person3");
String value_4 = Firebase.getString("person4");
String value_5 = Firebase.getString("person5");
String value_6 = Firebase.getString("person6");


if(value_1 == "1") 
{
  digitalWrite(D7,HIGH);
  
}
if(value_1 == "0")
{
   digitalWrite(D7,LOW);
  
}
if (value_1 == "" )
{
  digitalWrite(D7,LOW);
  
}
if(value_2 == "1") 
{
  digitalWrite(D6,HIGH);
  
}
if(value_2 == "0")
{
   digitalWrite(D6,LOW);
  
}
if (value_2 == "" )
{
  digitalWrite(D6,LOW);
  
}


if(value_3 == "1") 
{
  digitalWrite(D5,HIGH);
  
}
if(value_3 == "0")
{
   digitalWrite(D5,LOW);
  
}
if (value_3 == "" )
{
  digitalWrite(D5,LOW);
  
}

if(value_4 == "1") 
{
  digitalWrite(D4,HIGH);
  
}
if(value_4 == "0")
{
   digitalWrite(D4,LOW);
  
}
if (value_4 == "" )
{
  digitalWrite(D4,LOW);
  
}


if(value_5 == "1") 
{
  digitalWrite(D3,HIGH);
  
}
if(value_5 == "0")
{
   digitalWrite(D3,LOW);
  
}
if (value_5 == "" )
{
  digitalWrite(D3,LOW);
  
}


if(value_6 == "1") 
{
  digitalWrite(D1,HIGH);
  
}
if(value_6 == "0")
{
   digitalWrite(D1,LOW);
  
}
if (value_6 == "" )
{
  digitalWrite(D1,LOW);
  
}
if(digitalRead(d8) == LOW) //If the adressee presses a button reset all the lights
{
Firebase.setString("person1", "0");
Firebase.setString("person2", "0");
Firebase.setString("person3", "0");
Firebase.setString("person4", "0");
Firebase.setString("person5", "0");
Firebase.setString("person6", "0");
 
}

delay(2000);
if (WiFi.status() != WL_CONNECTED)
{
 
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
}

}


 
