#include <Keypad.h>

const byte ROWS = 4; //four rows

const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B' },

  {'7','8','9','C'},

  {'*','0','#','D'}

};
byte colPins[ROWS] = {28, 26, 24, 22}; //connect to the row pinouts of the keypad
byte rowPins[COLS] = {36, 34, 32, 30};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  Serial.begin(9600);

}

void loop(){

  char key = keypad.getKey();

  if (key != NO_KEY){

    Serial.println(key);

  }

}

