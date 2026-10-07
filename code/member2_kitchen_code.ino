#include "DHT.h"

// ================= MEMBER 2 PINS =================
#define DHTPIN 15 // DHT11 Data Pin
#define DHTTYPE DHT11 // DHT 11
#define SOUND_PIN 36 // MAX9814 Sound Sensor (SP / VP)
#define BUZZER_PIN 23 // Active Buzzer
#define RELAY_PIN 22 // Relay for Exhaust Fan

// ================= SMART KITCHEN THRESHOLDS =================
// 1. Normal Cooking Limit
const float NORMAL_COOKING_TEMP = 35.0;  

// 2. Danger Limit
const float HAZARD_TEMP_THRESHOLD = 48.0; 

// 3. Sound Threshold (To ignore high sound of pressure cooker, we gave high threshold)
const int SOUND_WARNING_THRESHOLD = 3200;    
const int SOUND_HAZARD_THRESHOLD = 3800; // explosion

DHT dht(DHTPIN, DHTTYPE);

bool stoveFire = false; 

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Pin Modes
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RELAY_PIN, HIGH);
  
  dht.begin();
  Serial.println("==================================================");
  Serial.println(" SMART KITCHEN SYSTEM - PRESSURE COOKER OPTIMIZED ");
  Serial.println("==================================================");
}

void loop() {
  // --- SENSOR READINGS ---
  float currentTemp = dht.readTemperature();
  int soundVal = analogRead(SOUND_PIN);

  // Print values in serial monitor
  Serial.print("Temp: ");
  Serial.print(currentTemp);
  Serial.print(" °C | Sound: ");
  Serial.println(soundVal);

  // --- SMART DECISION LOGIC ---
  bool isCookingNormal = false;
  bool isEmergency = false;

  // Temperature and Sound Check
  if (currentTemp >= NORMAL_COOKING_TEMP && currentTemp < HAZARD_TEMP_THRESHOLD) {
    isCookingNormal = true; 
  }
  
  if (currentTemp >= HAZARD_TEMP_THRESHOLD || soundVal >= SOUND_HAZARD_THRESHOLD) {
    isEmergency = true; 
  }

  // --- OUTPUT ACTUATOR LOGIC ---
  if (stoveFire || isEmergency) 
  {
    digitalWrite(RELAY_PIN, LOW); 
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("[CRITICAL ALERT] Burning Food / Danger Detected! Fan & Buzzer ON");
  } 
  else if (isCookingNormal)
  {
    digitalWrite(RELAY_PIN, LOW); 
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("[INFO] Normal Cooking / Pressure Cooker Active. Ventilation ON (Buzzer OFF)");
  }
  else 
  {
    digitalWrite(RELAY_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("[STATUS] Kitchen Safe. All Normal.");
  }

  delay(1500);
}


