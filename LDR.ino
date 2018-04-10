#include <LiquidCrystal.h>
unsigned int rd;
int sensorPin = A0; // select the input pin for LDR

 
int sensorValue = 0; // variable to store the value coming from the sensor 
void setup() { 
  Serial.begin(9600); //sets serial port for communication

} 
void loop() {

rd = analogRead(A1);
analogWrite(9,rd/4);

sensorValue = analogRead(sensorPin); // read the value from the sensor 
  if(sensorValue<155){
    Serial.println("SENSOR <100 ALERT!!!!");
    analogWrite(9,rd/4);
  }else{
    digitalWrite(9,0);
  }
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen 
  delay(125); 
}




