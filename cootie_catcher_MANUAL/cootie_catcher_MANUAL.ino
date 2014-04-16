#include <Servo.h> 

Servo myservo1;
Servo myservo2;

//const int numReadings = 10;
//
//int readings[numReadings];      // the readings from the analog input
//int index = 0;                  // the index of the current reading
//int total = 0;                  // the running total
//int average = 0;                // the average

const int sensorPin1 = A0;  
const int sensorPin2 = A2;

int sensorValue1 = 0;         // the sensor value
int sensorMin1 = 1023;        // minimum sensor value
int sensorMax1 = 0;           // maximum sensor value
//
int sensorValue2 = 0;         // the sensor value
int sensorMin2 = 1023;        // minimum sensor value
int sensorMax2 = 0;           // maximum sensor value
int counter1 = 0;
int counter2 = 0;


void setup() {
  myservo1.attach(9);
  myservo2.attach(10);
  
  Serial.begin(9600);                   
      
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds 
//  while (millis() < 5000) {
//    sensorValue1 = analogRead(sensorPin1);
//
//    // record the maximum sensor value
//    if (sensorValue1 > sensorMax1) {
//      sensorMax1 = sensorValue1;
//    }
//
//    // record the minimum sensor value
//    if (sensorValue1 < sensorMin1) {
//      sensorMin1 = sensorValue1;
//    }
//    sensorValue2 = analogRead(sensorPin2);
//
//    // record the maximum sensor value
//    if (sensorValue2 > sensorMax2) {
//      sensorMax2 = sensorValue2;
//    }
//
//    // record the minimum sensor value
//    if (sensorValue2 < sensorMin2) {
//      sensorMin2 = sensorValue2;
//    }
//  }

  // signal the end of the calibration period
 // digitalWrite(13, LOW);
 
 
 myservo1.write(0);
 myservo2.write(90);
 
 
}

void loop() {
//  myservo1.write(50);
//  delay(1000);
//  myservo1.write(0);
//  delay(1000);
//  myservo2.write(40);
//  delay(1000);
//  myservo2.write(90);
//  delay(1000);
  
  
  // read the sensor:
  sensorValue1 = analogRead(sensorPin1);
  // apply the calibration to the sensor reading
  sensorValue1 = map(sensorValue1, sensorMin1, sensorMax1, 0, 100);
  // in case the sensor value is outside the range seen during calibration
  sensorValue1 = constrain(sensorValue1, 0, 100);
  
  
   sensorValue2 = analogRead(sensorPin2);
  // apply the calibration to the sensor reading
  sensorValue2 = map(sensorValue2, sensorMin2, sensorMax2, 0, 100);
  // in case the sensor value is outside the range seen during calibration
  sensorValue2 = constrain(sensorValue2, 0, 100);


  if(sensorValue1 > 10 && counter2==0)
    {
      myservo1.write(50);  
      counter1 = 1;
    }
    
  if(sensorValue1 <= 10)
    {
      myservo1.write(0);
      counter1 = 0;
    }
    
    
   if(sensorValue2 > 50 && counter1 == 0)
    {
      myservo2.write(40);  
      counter2 = 1;
    }
    
  if(sensorValue2 <= 50)
    {
      myservo2.write(90);
      counter2 = 0;
    }
  
  delay(100);   
}
