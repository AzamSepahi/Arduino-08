#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4;
int led = 13;
int firstNumber = 0;
int fn = 0;
bool tf = false;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2};
byte rowPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.println("please set password:");
  delay(2000);
  for (int i = 0; i < 4; i++) {
    int button = int(customKeypad.getKey()) - 48;
    if (0 <= button && button <= 10) {
      Serial.print(button);
      firstNumber = firstNumber * 10 + button;
    }
  }
}
void loop() {
  Serial.println("please enter password:");
  for (int i = 0; i < 4; i++) {
    int button = int(customKeypad.getKey()) - 48;
    if (0 <= button && button <= 10) {
      Serial.print(button);
      fn = fn * 10 + button;
    }
    if (firstNumber == fn) {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
  }
}
