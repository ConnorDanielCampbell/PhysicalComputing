/* SCOOBY DOO COMBINATION LOCK BOOKSHELF

by Connor Campbell
9 February 2014
#2389765

This code uses photocell resistors installed in a bookshelf 
to monitor the removal/replacing of books to activate a sound.

It is based on: 
-the Arduino "Calibration" code, 
-the "1 button 3 LEDs" code I used for lab #2
-the "Tone" Arduino example code

*/


 #include "pitches.h"

const int sensorPin0 = A0;    
const int sensorPin1 = A2;
const int sensorPin2 = A3;

const int led11 = 11;       
const int led10 = 10;
const int led9 = 9;

const int speaker = 3;
int melody[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6};
int noteDurations[] = {16, 16, 16, 16, 16, 16, 4};

int sensorValue0 = 0;        
int sensorMin0 = 1023;        
int sensorMax0 = 0; 

int sensorValue1 = 0;        
int sensorMin1 = 1023;        
int sensorMax1 = 0; 

int sensorValue2 = 0;        
int sensorMin2 = 1023;        
int sensorMax2 = 0; 

int bright = 100;

int counter = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(13, HIGH);

  while (millis() < 8000) {
    
    //sensor A0
    sensorValue0 = analogRead(sensorPin0);
    if (sensorValue0 > sensorMax0) 
    {
      sensorMax0 = sensorValue0;
    }
    if (sensorValue0 < sensorMin0) 
    {
      sensorMin0 = sensorValue0;
    }
    
    //sensor A1
    sensorValue1 = analogRead(sensorPin1);
    if (sensorValue1 > sensorMax1) 
    {
      sensorMax1 = sensorValue1;
    }
    if (sensorValue1 < sensorMin1) 
    {
      sensorMin1 = sensorValue1;
    }
    
    //sensorA2
    sensorValue2 = analogRead(sensorPin2);
    if (sensorValue2 > sensorMax2) 
    {
      sensorMax2 = sensorValue2;
    }
    if (sensorValue2 < sensorMin2) 
    {
      sensorMin2 = sensorValue2;
    }
  }
  
   digitalWrite(13, LOW);
 }

void loop() {

    sensorValue0 = analogRead(sensorPin0);
    sensorValue0 = map(sensorValue0, sensorMin0, sensorMax0, 0, 255);
    sensorValue0 = constrain(sensorValue0, 0, 255);
  
    sensorValue1 = analogRead(sensorPin1);
    sensorValue1 = map(sensorValue1, sensorMin1, sensorMax1, 0, 255);
    sensorValue1 = constrain(sensorValue1, 0, 255);
  
    sensorValue2 = analogRead(sensorPin2);
    sensorValue2 = map(sensorValue2, sensorMin2, sensorMax2, 0, 255);
    sensorValue2 = constrain(sensorValue2, 0, 255);
    
    Serial.print("sensor0 = " );                       
    Serial.print(sensorValue0);  

    Serial.print("sensor1 = " );                       
    Serial.print(sensorValue1);  

    Serial.print("sensor2 = " );                       
    Serial.print(sensorValue2);      
  
  if (counter >= 4) 
    {
      counter = 0;
    }
  
  if (counter == 0)
    {
      if (sensorValue0 < bright && sensorValue1 < bright && sensorValue2 > bright) 
        {
          counter++;
        }
    }
     
  if (counter == 1)
    {
      digitalWrite(led11, HIGH); 
      
      if (sensorValue0 < bright && sensorValue1 > bright && sensorValue2 < bright)
        {
          counter++;
        }
    }
     
  if (counter == 2)
    {
      digitalWrite(led11, HIGH); 
      digitalWrite(led10, HIGH);
      
      if (sensorValue0 > bright && sensorValue1 < bright && sensorValue2 < bright)
        {
          counter++;
        }
    }
     
     if (counter == 3)
       {
          digitalWrite(led11, HIGH); 
          digitalWrite(led10, HIGH);
          digitalWrite(led9, HIGH);
          
         for (int thisNote = 0; thisNote < 7; thisNote++) 
           {
            int noteDuration = 1000/noteDurations[thisNote];
            tone(3, melody[thisNote],noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(7);
           }
           delay(4000);
           counter++;
       }

 }
