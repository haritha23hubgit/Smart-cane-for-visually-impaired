// Smart Cane for the Visually Impaired

// --- Pin Definitions ---
#define TRIG_PIN 2
#define ECHO_PIN 3
#define VIBRATION_PIN 4

#define WATER_SENSOR_PIN A0
#define LDR_SENSOR_PIN A1
#define BUZZER_PIN 5

#define EMERGENCY_BUTTON_PIN 6
#define BLUETOOTH_TX 7
#define BLUETOOTH_RX 8
#define GPS_RX 9
#define GPS_TX 10

// --- Constants ---
#define OBSTACLE_THRESHOLD 50  // cm
#define WATER_THRESHOLD 300
#define DARKNESS_THRESHOLD 600

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);  // TX, RX
SoftwareSerial gps(GPS_RX, GPS_TX);                    // RX, TX

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(VIBRATION_PIN, OUTPUT);

  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(LDR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(EMERGENCY_BUTTON_PIN, INPUT_PULLUP);

  bluetooth.begin(9600);
  gps.begin(9600);

  Serial.begin(9600);
}

void loop() {
  checkObstacle();
  checkWater();
  checkDarkness();
  checkEmergencyButton();
}

void checkObstacle() {
  long duration;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance < OBSTACLE_THRESHOLD) {
    digitalWrite(VIBRATION_PIN, HIGH);
  } else {
    digitalWrite(VIBRATION_PIN, LOW);
  }
}

void checkWater() {
  int waterVal = analogRead(WATER_SENSOR_PIN);
  if (waterVal < WATER_THRESHOLD) {
    tone(BUZZER_PIN, 1000);  // tone 1
    delay(300);
    noTone(BUZZER_PIN);
  }
}

void checkDarkness() {
  int lightVal = analogRead(LDR_SENSOR_PIN);
  if (lightVal < DARKNESS_THRESHOLD) {
    tone(BUZZER_PIN, 1500);  // tone 2
    delay(300);
    noTone(BUZZER_PIN);
  }
}

void checkEmergencyButton() {
  static bool sent = false;
  if (digitalRead(EMERGENCY_BUTTON_PIN) == LOW && !sent) {
    sent = true;

    String gpsData = "";
    unsigned long startTime = millis();
    while (millis() - startTime < 5000) {
      if (gps.available()) {
        gpsData += char(gps.read());
      }
    }

    // Normally you'd parse GPS NMEA to extract lat/lon, but here we send raw data
    bluetooth.println("EMERGENCY! User Location:");
    bluetooth.println(gpsData);
  }

  if (digitalRead(EMERGENCY_BUTTON_PIN) == HIGH) {
    sent = false; // Reset after button release
  }
}