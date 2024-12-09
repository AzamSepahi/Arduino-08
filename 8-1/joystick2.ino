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
