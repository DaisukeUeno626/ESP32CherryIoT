const int touchPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

// --- 【重要】音程の定義（これがないとエラーになります） ---
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define REST     0

// テンポ設定
int eighth = 150; 
int quarter = 300;

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  ledcAttach(spkrPin, 12000, 8);    // ESP32-C3用の設定
}

void play(int freq, int duration) {
  if (freq > 0) {
    ledcWriteTone(spkrPin, freq);
  } else {
    ledcWriteTone(spkrPin, 0);
  }
  // 音を少し短く切って「ピコピコ感」を出す
  delay(duration * 0.8);
  ledcWriteTone(spkrPin, 0);
  delay(duration * 0.2);
}


void loop() {
  //Look at the serial monitor
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Hello World");
    delay(200);
  // --- Aメロ ---
  play(NOTE_E5, quarter); play(NOTE_B4, eighth); play(NOTE_C5, eighth); play(NOTE_D5, quarter); play(NOTE_C5, eighth); play(NOTE_B4, eighth);
  play(NOTE_A4, quarter); play(NOTE_A4, eighth); play(NOTE_C5, eighth); play(NOTE_E5, quarter); play(NOTE_D5, eighth); play(NOTE_C5, eighth);
  play(NOTE_B4, quarter); play(NOTE_B4, eighth); play(NOTE_C5, eighth); play(NOTE_D5, quarter); play(NOTE_E5, quarter);
  play(NOTE_C5, quarter); play(NOTE_A4, quarter); play(NOTE_A4, quarter); play(REST, quarter);

  // --- Bメロ ---
  play(NOTE_D5, quarter + eighth); play(NOTE_F5, eighth); play(NOTE_A5, quarter); play(NOTE_G5, eighth); play(NOTE_F5, eighth);
  play(NOTE_E5, quarter + eighth); play(NOTE_C5, eighth); play(NOTE_E5, quarter); play(NOTE_D5, eighth); play(NOTE_C5, eighth);
  play(NOTE_B4, quarter); play(NOTE_B4, eighth); play(NOTE_C5, eighth); play(NOTE_D5, quarter); play(NOTE_E5, quarter);
  play(NOTE_C5, quarter); play(NOTE_A4, quarter); play(NOTE_A4, quarter); play(REST, quarter);
  }
    Serial.println("not Touch");
    delay(200);
}
