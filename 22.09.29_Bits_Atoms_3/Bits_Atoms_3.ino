#define ledPin 11

void setup() {
  pinMode(ledPin,OUTPUT);
}

void threeshortblinks() {
  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(200);
  digitalWrite(ledPin,LOW);
  delay(1200);
}

void threelongblinks() {
  digitalWrite(ledPin,HIGH);
  delay(800);
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(800);
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(800);
  digitalWrite(ledPin,LOW);
  delay(1200);
}

void loop() {
  threeshortblinks();
  threelongblinks();
  threeshortblinks();
  digitalWrite(ledPin,LOW);
  delay(1000);
}