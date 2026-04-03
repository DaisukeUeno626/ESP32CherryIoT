const int vibPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  pinMode(vibPin, OUTPUT);
}

void loop() {
  digitalWrite(vibPin, HIGH);
  delay(2000);
  digitalWrite(vibPin, LOW);
  delay(1000);
}
