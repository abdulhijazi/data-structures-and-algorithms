//driver program for IoT window

#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {  
  #define pwm1 9 //pin 9 used for controlling actuator speed
  #define dir1 A1 //pin A1 used for actuator direction
  #define pot A0 //pin A0 reads actuators feedback for updates on amount opened/closed
  #define v5v A2 //digital pin to power actuator POT
  pinMode(v5v, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir1, OUTPUT);
  digitalWrite(v5v, HIGH);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

 float readPot()
 {
   delay(500);
   int potValue = analogRead(pot);
   Serial.println(analogRead(pot));
   float feedback = 12*potValue/682;
   //actuator is 12" long, max analog read is 1024 when powered by 5V, since powered by 3.3V max read is 1024*(2/3) = 682
   return feedback;
 }
 
 void openWin(){
   float x1 = readPot();
   digitalWrite (dir1, HIGH); //set actuator to open direction
   analogWrite (pwm1, 254); //turn actuator on to max speed
   while (x1<8.0){ //actuator to open 8 inches due to size of window
    x1 = readPot(); //reads actuator feedback to check for current position
   }
   analogWrite(pwm1,0); //stop actuator
   return;
 }

 void closeWin(){
   float x2 = readPot();
   digitalWrite (dir1, LOW); //set actuator to closing direction
   analogWrite (pwm1, 254); //turn on actuator
   while (x2>0.2) { //0.2 is near the complete closed position, gives the program time to continue faster
    x2=readPot(); //reads actuator feedback to check for current position
   }
   analogWrite(pwm1,0); //stop actuator
   return;
 }

void onWindowChange() { //opens or closes upon detecting change from cloud
  if(window==1)
  openWin();
  else
  closeWin();
}










