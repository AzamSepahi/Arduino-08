## آزمایش 2-8:
### جوی استیک (joystick) به همراه بازر
### هدف:
#### با هدایت دسته ی جوی استیک به راست و چپ بازر آلارم دهد
---
## ابزار:

|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|7|
|2|جوی استیک|1|
|3|ریزپردازنده|1|
|4|برد بورد|1|
|5|بازر|1|
---
### شرح آزمایش:
#### در این برنامه به جای نمایش جهت در سریال مانیتور، زمانی که به چپ یا راست هدایت شود،بازر به صدا در می آید.
---
### شماتیک مدار:
![](/media/shemajoystickbuzzer.jpg)
---
### کد برنامه:
```cpp
const int SW = 2; // SW
const int X = 0; // VRx
const int Y = 1; // VRy
const int buzzer = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {


  Serial.print("Switch: ");
  Serial.print(digitalRead(SW));
  Serial.print("\t\t");
  Serial.print("VRx: ");
  Serial.print(analogRead(X));
  Serial.print("\t\t");
  Serial.print("VRy: ");
  Serial.println(analogRead(Y));
  Serial.println("_______");
  delay(500);
  if (analogRead(Y) > 1000)
  {
    tone(buzzer, 1000);
    delay(1000);
  }
  if (analogRead(Y) < 200)
  {
    tone(buzzer, 800);
    delay(1000);
  }
  noTone(buzzer);
  delay(1000);
}```
