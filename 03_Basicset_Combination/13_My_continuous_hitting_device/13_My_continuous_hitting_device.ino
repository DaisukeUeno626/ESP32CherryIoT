#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB

Servo myservo;
int level = 0;
int speed = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
  myservo.attach(motorPin);
}

void loop() {
  if (digitalRead(swPin) == HIGH){
    level = level + 1;
    if (level == 3){
      level =0;
    }
    Serial.print("level:");
    Serial.println(level);
  }
  speed = level * 1;
  // 0-180 right
  for(int angle = 0; angle <= 180; angle++) {                        
    myservo.write(angle);
    delay(speed);
  }
  // 180-0  left 
  for(int angle = 180; angle >= 0; angle--) {                 
    myservo.write(angle);  
    delay(speed);      
  }

}