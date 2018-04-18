#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define analogPin A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor
//light sensor val 
int sensorPin = A0; // select the input pin for LDR 
int sensorValue = 0; // variable to store the value coming from the sensor
//Temp Sensors val
int ThermistorPin = 0;
const int motorPin = 3 ;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf; //value of each Temerature
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup()
{
  // set up the LCD's number of columns and rows: 
  lcd.begin();
  lcd.backlight(); //open the backlight 
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
}
int light(){
sensorValue = analogRead(sensorPin); // read the value from the sensor 
Serial.println(sensorValue); //prints the values coming from the sensor on the screen 
delay(500); 
}
void Drive(float Tc){
  if (Tc >= 28.00) {
   //mortor on 
   digitalWrite(motorPin, HIGH);
  }
  else if (Tc < 28 && Tc >= 24 ){
   //slow down
   analogWrite(motorPin,80);
  }
  else if(Tc<23)  {
    //motor off
    digitalWrite(motorPin, LOW); 
  }
  else {
    digitalWrite(motorPin, LOW); 
  }
}
void loop()
{
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 
  Serial.print("Centigrade ");
  Serial.println(Tc); 
  Serial.print("Fahrenheit ");
  Serial.println(Tf); 
  Serial.println("");
  // Print a message of "Temp: "to the LCD.
  lcd.setCursor(0, 0);// set the cursor to column 0, line 1
  lcd.print("Home Sweet Home");
  lcd.setCursor(0, 1);// set the cursor to column 0, line 0
  lcd.print("Temp: "); // Print a message of "Temp: "to the LCD.
  lcd.print(Tc); // Print a centigrade temperature to the LCD.
  // Print the unit of the centigrade temperature to the LCD.
  lcd.write(char(223));
  lcd.print("C");//print the unit" ℃ "
  delay(200); //wait for 100 milliseconds
  //call Functuion
  Drive(Tc);
  light();
}
 
