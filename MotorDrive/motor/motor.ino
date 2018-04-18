// constant pin for the transistor connected to the motor
const int motorPin = 2;

void setup() { //set motorPin as OUTPUT 
  pinMode(motorPin, OUTPUT); 
}

void loop() { // milliseconds to turn the motor on 
  int onTime = 3000; // milliseconds to turn the motor off 
  int offTime = 3000;

// turn the motor on (full speed) 
digitalWrite(motorPin, HIGH); // delay for onTime milliseconds 
delay(onTime); // turn the motor off 
digitalWrite(motorPin, LOW); // delay for offTime milliseconds 
delay(offTime); }
