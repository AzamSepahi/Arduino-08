#include <Keypad.h>
int led = 13;
float pass = 0;
float firstNumber = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(led , OUTPUT);
  Serial.println("set password : ");

  for (int i = 0 ; i < 4 ; i++) {
    int button = int(customKeypad.getKey()) - 48;
    Serial.println(button);
    if (0 <= button && button <= 10) {
      Serial.print(button);
      pass = pass * 10 + button;
      //      i = i + 1;
    }
  }
  Serial.println("set password is copmleted, Enter code:");
}
void loop() {

//  Serial.println("enter the password");

  int button = int(customKeypad.getKey()) - 48;
  if (0 <= button && button <= 10) {
    Serial.print(button);
    for (int i = 0 ; i < 4 ; i++) {
      firstNumber = firstNumber * 10 + button;
//      i = i + 1;
    }
  }

  if ( pass == firstNumber) {
    digitalWrite(led , HIGH);

  }
  else {
    digitalWrite(led , LOW);

  }
  firstNumber = 0;
  delay(1000);

}

