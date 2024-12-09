## آزمایش 1-8:
### جوی استیک (joystick)
### هدف:
#### نمایش جهت های(بالاريالپایین،راست،چپ)در سریال مانیتور
---
## ابزار:

|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|5|
|2|جوی استیک|1|
|3|ریزپردازنده|1|
|4|برد بورد|1|
---
### شرح آزمایش:
#### با وصل کردن پایه های جوی استیک به پایه های مربوطه در آردوینو و هدایت دسته ی متحرک آن به جهات مختلف،
#### در سریال مانیتور مشاهده می کنیم که جهات مختلف را نشان می دهید.
---
### شماتیک مدار:
![](/media/shemajoystick.jpg)
---
### کد برنامه:
```cpp
const int SW = 2; // SW
const int X = 0; // VRx
const int Y = 1; // VRy

void setup() {
  // put your setup code here, to run once:
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
    Serial.println("right");
  }
  if (analogRead(Y) < 200)
  {
    Serial.println("left");
  }

  if (analogRead(X) < 200)
  {
    Serial.println("down");
  }
  if (analogRead(X) > 1000)
  {
    Serial.println("up");
  }
}
```

