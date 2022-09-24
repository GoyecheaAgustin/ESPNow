#include <Arduino.h>

/*
  ESP-NOW- Receptor

*/

// Include Libraries
#include <esp_now.h>
#include <WiFi.h>
#define RELE1 19
#define RELE2 18
#define RELE3 17
#define RELE4 16
// Define a data structure
typedef struct struct_message {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
} struct_message;

// Create a structured object
struct_message myData;


// Callback function executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  if (myData.a==1){
    digitalWrite(RELE1, LOW);
  }else {
      digitalWrite(RELE1, HIGH);
  }

  if (myData.b==1){
    digitalWrite(RELE2, LOW);
  }else {
      digitalWrite(RELE2, HIGH);
  }
  if (myData.c==1){
    digitalWrite(RELE3, LOW);
  }else {
      digitalWrite(RELE3, HIGH);
  }
  if (myData.d==1){
    digitalWrite(RELE4, LOW);
  }else {
      digitalWrite(RELE4, HIGH);
  }
}

void setup() {
  // Set up Serial Monitor
  Serial.begin(9600);

  pinMode(RELE1, OUTPUT);
  digitalWrite(RELE1, HIGH);
   pinMode(RELE2, OUTPUT);
  digitalWrite(RELE2, HIGH);
   pinMode(RELE3, OUTPUT);
  digitalWrite(RELE3, HIGH);
   pinMode(RELE4, OUTPUT);
  digitalWrite(RELE4, HIGH);

  
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}