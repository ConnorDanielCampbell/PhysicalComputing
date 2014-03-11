 #include "pitches.h"

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

int count = 0;


void setup() {
  
  Serial.begin(9600);
  
  //calibration
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  while (millis() < 5000) 
  {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax) 
    {
      sensorMax = sensorValue; 
    }

    if (sensorValue < sensorMin) 
    {
      sensorMin = sensorValue;
    }
  }
  digitalWrite(13, LOW);
  // end of calibration
}

void loop() {
  
  while (millis() < 10000 && millis() > 5000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_G4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_AS5);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_D5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_G5);
      }
  }
  
  while (millis() > 10000 && millis() < 15000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_FS4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_AS5);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_D5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_FS5);
      }
  }  
  
  while (millis() > 15000 && millis() < 20000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_F4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_AS5);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_D5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_F5);
      }
  }  
  
  while (millis() > 20000 && millis() < 25000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_E4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_A5);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_CS5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_E5);
      }
  }  
  
  while (millis() > 25000 && millis() < 30000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_DS4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_GS4);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_C5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_DS5);
      }
  }  

  while (millis() > 30000 && millis() < 35000)
  {
    Serial.println(sensorValue);

    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 10);
    sensorValue = constrain(sensorValue, 0, 10);
    
    if(sensorValue == 8) 
      {
        tone(9, NOTE_D4);
      }
    if(sensorValue == 6) 
      {
        tone(9, NOTE_FS4);
      }
    if(sensorValue == 4) 
      {
        tone(9, NOTE_A5);
      }
    if(sensorValue == 2) 
      {
        tone(9, NOTE_D5);
      }
  }  
  
}
