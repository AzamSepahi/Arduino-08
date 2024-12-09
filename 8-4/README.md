## آزمایش 4-8:
### ورود رمز
### هدف:
#### روشن شدن LED با وارد کردن رمز صحیح
---
## ابزار:

|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|10|
|2|LED|1|
|3|مقاومت|1|
|4|برد بورد|1|
|5|ریزپردازنده|1|
|6|کیبرد|1|
---
### شرح آزمایش:
#### در کد برنامه رمزی 4 رقمی برای روشن شدن LED در نظر میگیریم به گونه ای که اگر کاربر
#### رمز را صحیح وارد نماید LED روشن شود و در غیر این صورت خاموش شود.
---
### شماتیک مدار:
![](/media/shemapass.jpg)
---
### کد برنامه :
```cpp
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4;
int led = 11;
int firstNumber = 0;

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
}
void loop() {
  int button = int(customKeypad.getKey()) - 48;
  if (0 <= button && button <= 10) {
    Serial.print(button);
    firstNumber = firstNumber * 10 + button;
    if (firstNumber == 1234) {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
     
    }
          Serial.clear();

  }
}
```

