#include <X_NODE_esp32wroom.h>
X_NODE_esp32wroom xnode;

#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

unsigned long previousMillis = 0;
const long interval = 500;
char auth[] = "BB1xLSHcnBUGeTdI1R4FTTTrc9ygpcLL"; //Enter your token here
int cont = 0;

int pin_led = 12; //Pin built-in led 

void setup() {
  pinMode(pin_led, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Blynk.begin(auth);
}

void ReadData(void) {
  float VH = xnode.ReadAnswerToFloat("030A", "GH");  //Saves the X-NODE voltmeter (0V-20V) reading 
  float VL = xnode.ReadAnswerToFloat("030A", "GL");  //Saves the X-NODE voltmeter (0V-5V) reading 
  Blynk.virtualWrite(V0, VH);
  Blynk.virtualWrite(V1, VL);
}

void loop() {
  Blynk.run();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ReadData();
    digitalWrite(pin_led, HIGH); delay(100);
    digitalWrite(pin_led, LOW);
  }
}
