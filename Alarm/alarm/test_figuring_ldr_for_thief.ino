#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define analogPin A2 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor
#define Password_Length 5 // password range
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

//keypad

char Data[Password_Length]; 
char Master[Password_Length] = "1234"; 
byte data_count = 0, master_count = 0;
char customKey;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B' },
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte colPins[ROWS] = {28, 26, 24, 22}; //connect to the row pinouts of the keypad
byte rowPins[COLS] = {36, 34, 32, 30}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

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

sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.print("sensor light::");
Serial.println(sensorValue);
  if(sensorValue<155){
    Serial.println("SENSOR <155 ALERT!!!!");
    analogWrite(9,250);
  }else{
    digitalWrite(9,0);
  }

    Serial.println(sensorValue); //prints the values coming from the sensor on the screen
    delay(500);

}


void Drive(float Tc){
    if (Tc >= 28.00) {
        //mortor on when it's hot
        digitalWrite(motorPin, HIGH);
        Serial.println("Turn Fan ON (Tc >= 28)");
    }
    else if (Tc < 28 && Tc >= 24 ){
        //slow down
        analogWrite(motorPin,80);
        Serial.println("Turn Fan ON (Tc<28 and Tc>=24)");
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
      while(thief) {
          passcode();
          tone(buzzerPin, 1000);
          passcode();
          digitalWrite(ledPin, HIGH);
          passcode();
          delay(100);
          passcode();
          noTone(buzzerPin);
          passcode();
          digitalWrite(ledPin, LOW);
          passcode();
          delay(100);
          passcode();
          //off blink
          Serial.println("----------- ALARM ACTIVATED -----------");
          passcode();
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
  //while(true){
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
    
    delay(5000); //wait for 100 milliseconds
    //call Functuion
    lcd.clear();
    lcd.setCursor(0, 0);// set the cursor to column 0, line 1
    lcd.print("Test1");
    lcd.setCursor(0, 1);// set the cursor to column 0, line 0  
    lcd.print("Test2"); // Print a message of "Temp: "to the LCD.
    delay(5000);

    Serial.print("sensor thief::");
    Serial.println(ldrStatus);
    if(ldrStatus <= 150){ //LDR detect thief
      thief=true;
      lcd.clear();
      lcd.setCursor(0, 0);// set the cursor to column 0, line 1
      lcd.print("Intruder!!!");
      //break;
     
  
    }

 
 
  //}
}
void passcode(){

  char customKey = customKeypad.getKey(); //get key from keypad one by one
  if (customKey){//if recieve key
    Data[data_count] = customKey; //put 'customKey' in array "Data" at Index = 'data_count'
    lcd.setCursor(data_count,1); 
    lcd.print(Data[data_count]);
    data_count++; //go to next character
    }

  if(data_count == Password_Length-1){ // if write all passcode character
    
    if(!strcmp(Data, Master)){ // if passcode CORRECT
        thief=false; //BREAK THE WHILE-LOOP
      }
    else{ //if passcode INCORRECT
      lcd.setCursor(0, 1); // set the cursor to column 0, line 1
      delay(100);
      lcd.print("INCORRECT !!!");
      delay(200);
      }
    
    clearData();//clear all password array
    lcd.clear();
    lcd.setCursor(0, 0);// set the cursor to column 0, line 1
    lcd.print("Intruder!!!");
  }
}

void clearData(){ //for clear passward 
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
  
void loop(){
    float sensorValue = analogRead(sensorPin); // read the value from the sensor
    lcd.setCursor(0, 0);// set the cursor to column 0, line 0
    lcd.print("sensorValue: "); // Print a message of "Temp: "to the LCD.
    lcd.print(sensorValue);
    float ldrStatus = analogRead(ldrPin2);
    Serial.println(ldrStatus);
    lcd.setCursor(0, 1);// set the cursor to column 0, line 0
    lcd.print("LDR_status: "); // Print a message of "Temp: "to the LCD.
    lcd.print(ldrStatus);
    }
    //calling functions
    /*
    getTemp();
    firstLcd();
    alarm();
    Drive(Tc);
    light();
}   */


