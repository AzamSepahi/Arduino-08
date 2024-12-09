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
}
