#include <Arduino.h>
/*
  ESP-NOW - Transmisor

*/

// Include Libraries
#include <esp_now.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 
#define DISCRE1 32
#define DISCRE2 33
#define DISCRE3 25
#define DISCRE4 26


// MAC Address of responder
uint8_t broadcastAddress[] = {9C,9C,1F,CB,13,04};

// Define a data structure
typedef struct struct_message {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

} struct_message;

// Create a structured object
struct_message myData;

// Peer info
esp_now_peer_info_t peerInfo;

// Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  
  // Set up Serial Monitor
  Serial.begin(9600);
 
  pinMode(DISCRE1, INPUT);
  pinMode(DISCRE2, INPUT);
  pinMode(DISCRE3, INPUT);
  pinMode(DISCRE4, INPUT);

  lcd.clear();
  lcd.setCursor(5, 0);
    // print message
  lcd.print("BENDER");
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print("ERROR ESP-NOW");
    return;
  }

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
 //Testeo el estado de las entradas
  if (digitalRead(DISCRE1)){
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 1 ON");
      myData.a = 1;
    }else{
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 1 OFF");
      myData.a = 0;
    }
  

  if (digitalRead(DISCRE2)){
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 2 ON");
      myData.b = 1;
    }else{
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 2 OFF");
      myData.b = 0;
    }

  if (digitalRead(DISCRE3)){
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 3 ON");
      myData.c = 1;
    
  }else{
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 3 OFF");
      myData.c = 0;
  }
  if (digitalRead(DISCRE4)){
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 4 ON");
      myData.d = 1;
  }else{
      lcd.setCursor(0, 1);
      lcd.print("                 ");
      lcd.setCursor(0, 1);
      lcd.print("DIGITAL 4 OFF");
      myData.d = 0;
  }

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sending confirmed");
  }
  else {
    Serial.println("Sending error");
  }

}