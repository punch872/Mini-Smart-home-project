#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define analogPin A2 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor

//light sensor val 
int sensorPin = A0; // select the input pin for LDR 
int sensorValue = 0; // variable to store the value coming from the sensor
unsigned int rd;

//Temp Sensors val
int ThermistorPin = 2;
const int motorPin = 3 ;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf; //value of each Temerature
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//alarm val
const int ledPin = 13;
const int buzzerPin = 12;
const int ldrPin = A1;
const int ldrPin2 = A3;
boolean alarmOn=true;
boolean thief=false;
void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin();
    lcd.backlight(); //open the backlight
    Serial.begin(9600);
    pinMode(motorPin,OUTPUT);
//alarm pin mode 
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ldrPin, INPUT);
}

int light(){
<<<<<<< HEAD
rd = analogRead(ldrPin);
=======
rd = analogRead(A1);
>>>>>>> 3272763686eb8e9308b7fdff298c531b592cdf31
analogWrite(9,rd/4);
sensorValue = analogRead(sensorPin); // read the value from the sensor

  if(sensorValue<155){
    Serial.println("SENSOR <155 ALERT!!!!");
    analogWrite(9,rd/4);
  }else{
    digitalWrite(9,0);
  }
<<<<<<< HEAD
=======
    Serial.println(sensorValue); //prints the values coming from the sensor on the screen
    delay(500);


>>>>>>> 3272763686eb8e9308b7fdff298c531b592cdf31
}


void Drive(float Tc){
    if (Tc >= 28.00) {
        //mortor on when it's hot
        digitalWrite(motorPin, HIGH);
    }
    else if (Tc < 28 && Tc >= 24 ){
        //slow down
        analogWrite(motorPin,80);
    }
    else if(Tc<23)  {
        //motor off when temp is cold
        digitalWrite(motorPin, LOW);
    }
    else {
        digitalWrite(motorPin, LOW);
    }
}
void alarm(){
    //set pin numbers

      
  //ldrStatus >= 400
      while(thief) {
  //on blink
          tone(buzzerPin, 1000);
          digitalWrite(ledPin, HIGH);
          delay(100);
  
          noTone(buzzerPin);
          digitalWrite(ledPin, LOW);
          delay(100);

          
  //off blink
          Serial.println("----------- ALARM ACTIVATED -----------");
          //if(password to unactivate alarm ){theif =false;}
      }
    }

float getTemp(){
    //setup and display temperature
    Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    Tf = (Tc * 9.0)/ 5.0 + 32.0;
    
}
void firstLcd(){
  int ldrStatus = analogRead(ldrPin2);  //read the state of the LDR value
  while(alarmOn=!alarmOn){
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
    Serial.println(ldrStatus);
    delay(5000); //wait for 100 milliseconds
    //call Functuion
    lcd.clear();
    lcd.setCursor(0, 0);// set the cursor to column 0, line 1
    lcd.print("Test1");
    lcd.setCursor(0, 1);// set the cursor to column 0, line 0
    lcd.print("Test2"); // Print a message of "Temp: "to the LCD.
    delay(5000);


    
    if(ldrStatus <= 400){ //LDR detect thief
      thief=true;
      lcd.clear();
      lcd.setCursor(0, 0);// set the cursor to column 0, line 1
      lcd.print("Intruder!!!");
      break;
     
  
  }
 
  }
}  
void loop(){
    //calling functions
    
    getTemp();
    firstLcd();
    alarm();
    Drive(Tc);
    light();
}

<<<<<<< HEAD
=======
 
>>>>>>> 3272763686eb8e9308b7fdff298c531b592cdf31
