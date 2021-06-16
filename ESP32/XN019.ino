#include <X_NODE_esp32wroom.h>
X_NODE_esp32wroom xnode;

#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

unsigned long previousMillis = 0;
const long interval = 50;
char auth[] = "i4R0ItmcHt2tDkTXQ_0_rMKfaQWh0gMR"; //Enter your token here
int cont = 0; 

char Answer[20] = {};
int pin_led = 12; //Pin built-in led 

void setup() {
  pinMode(pin_led, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Blynk.begin(auth);
}

void ReadData(void) {
  xnode.ReadBinaryAnswer ("019A", "G", Answer); //Saves the X-NODE status reading 
  if (Answer[0] == '1')
    Blynk.virtualWrite(V0, 1);
  else
    Blynk.virtualWrite(V0, 0);

  if (Answer[1] == '1')
    Blynk.virtualWrite(V1, 1);
  else
    Blynk.virtualWrite(V1, 0);

  if (Answer[2] == '1')
    Blynk.virtualWrite(V2, 1);
  else
    Blynk.virtualWrite(V2, 0);

  if (Answer[3] == '1')
    Blynk.virtualWrite(V3, 1);
  else
    Blynk.virtualWrite(V3, 0);
    
  if (Answer[4] == '1')
    Blynk.virtualWrite(V4, 1);
  else
    Blynk.virtualWrite(V4, 0);

  if (Answer[5] == '1')
    Blynk.virtualWrite(V5, 1);
  else
    Blynk.virtualWrite(V5, 0);

  if (Answer[6] == '1')
    Blynk.virtualWrite(V6, 1);
  else
    Blynk.virtualWrite(V6, 0);

  if (Answer[7] == '1')
    Blynk.virtualWrite(V7, 1);
  else
    Blynk.virtualWrite(V7, 0);
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
