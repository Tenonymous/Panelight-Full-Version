#include <WiFi.h>
#include <HardwareSerial.h>
#include "HTTPClient.h"
#include "ArduinoJson.h"
#include <string.h>

#define RXD2 16
#define TXD2 17
#define BAUDRATE 9600


HardwareSerial PanelightSerial(2);

const unsigned short int numberOfWifies = 5;
// change numberOfWifies if you delete or add some new WiFi network 
char *ssids[] = {"Stejk", "Stejk", "Stejk", "Stejk", "Stejk"};
char *passwords[] = {"dawid123", "dawid123", "dawid123", "dawid123", "dawid123"};
   
char* ssid = ssids[0];
char* password = passwords[0];

const char* domainAddress = "http://192.168.43.144:8081/json";

int displaying_mode = 1;

  
void setup() {
 
  Serial.begin(115200);
  delay(4000);
  PanelightSerial.begin(BAUDRATE, SERIAL_8N1, RXD2, TXD2);
  delay(4000);
  WiFi.begin(ssid, password);

  int wifiConnectCounter = 1;
  int wifiSsidCounter = 0;
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
    wifiConnectCounter++;
    if(wifiConnectCounter % 10 == 0)
    {
      wifiSsidCounter++;
      ssid = ssids[wifiSsidCounter % numberOfWifies];
      password = passwords[wifiSsidCounter % numberOfWifies];
      WiFi.begin(ssid, password);
    }
  }

  Serial.println("Connected to the WiFi network");

}


int convertDisplayingMode(int currentMode, const char* currentColor)
{
  int temp = 0;
  if(currentMode == 1)
  {
    temp = 1;
  }
  else if(currentMode == 2)
  {
    temp = 2; 
  }
  else if(currentMode == 3)
  {
    if(strcmp(currentColor, "blue") == 0)
      temp = 3;
    else if(strcmp(currentColor, "blue2") == 0)
      temp = 4;
    else if(strcmp(currentColor, "green") == 0)
      temp = 5;
    else if(strcmp(currentColor, "orange") == 0)
      temp = 6;
    else if(strcmp(currentColor, "purple") == 0)
      temp = 7;
    else if(strcmp(currentColor, "purple_red") == 0)
      temp = 8;
    else if(strcmp(currentColor, "red_yellow") == 0)
      temp = 9;
    else if(strcmp(currentColor, "yellow") == 0)
      temp = 10;
    else if(strcmp(currentColor, "yellow_green") == 0)
      temp = 11;
      
  }
  else if(currentMode == 4)
  {
    if(strcmp(currentColor, "blue_dark") == 0)
      temp = 12;
    else if(strcmp(currentColor, "blue_green") == 0)
      temp = 13;
    else if(strcmp(currentColor, "green_violet") == 0)
      temp = 32;
    else if(strcmp(currentColor, "green_orange") == 0)
      temp = 14;
    else if(strcmp(currentColor, "green_red") == 0)
      temp = 15;
    else if(strcmp(currentColor, "orange_red") == 0)
      temp = 16;
    else if(strcmp(currentColor, "pink_darkblue") == 0)
      temp = 17;
    else if(strcmp(currentColor, "pink_red") == 0)
      temp = 18;
    else if(strcmp(currentColor, "yellow_blue") == 0)
      temp = 19;
  }
  else if(currentMode == 5)
  {
    if(strcmp(currentColor, "amber") == 0)
      temp = 20;
    else if(strcmp(currentColor, "gold") == 0)
      temp = 21;
    else if(strcmp(currentColor, "green") == 0)
      temp = 22;
    else if(strcmp(currentColor, "magenta") == 0)
      temp = 23;
    else if(strcmp(currentColor, "ocean") == 0)
      temp = 24;
    else if(strcmp(currentColor, "plum") == 0)
      temp = 25;
  }
  else if(currentMode == 6)
  {
    if(strcmp(currentColor, "amber_green") == 0)
      temp = 26;
    else if(strcmp(currentColor, "gold_magenta") == 0)
      temp = 27;
    else if(strcmp(currentColor, "ocean_amber") == 0)
      temp = 28;
    else if(strcmp(currentColor, "ocean_plum") == 0)
      temp = 29;
    else if(strcmp(currentColor, "red_gold") == 0)
      temp = 30;
    else if(strcmp(currentColor, "red_green") == 0)
      temp = 31;
  }

  return temp; 
}


void loop() {
  if (WiFi.status() == WL_CONNECTED) { 

    bool changeNeeded = false;
 
    HTTPClient http;
    http.begin(domainAddress);
    int httpCode = http.GET();
    
    if (httpCode > 0) {
        String payload = http.getString();
        StaticJsonDocument<500> jsonDoc;
        deserializeJson(jsonDoc, payload);

        int temp = convertDisplayingMode(jsonDoc["Id"], jsonDoc["Color"]);
        if(displaying_mode != temp)
        {
          displaying_mode = temp;
          changeNeeded = true;
        }
        if(changeNeeded)
        {
          PanelightSerial.write(temp);
          changeNeeded = false;
        }
        
    }
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end();
  }
 
  delay(1000);
}
