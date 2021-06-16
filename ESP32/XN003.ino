#include <X_NODE_esp32wroom.h>
X_NODE_esp32wroom xnode;
#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

unsigned long previousMillis = 0;
const long interval = 500;
char auth[] = "i4R0ItmcHt2tDkTXQ_0_rMKfaQWh0gMR"; //Enter your token here
int cont = 0;

int pin_led = 12; //Pin built-in led 

void setup() {
  pinMode(pin_led, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Blynk.begin(auth);
}

int Duty = 0;
int Dir = 0;
BLYNK_WRITE(1)
{
  Duty = param.asInt();
  if (Dir == 1)
    xnode.SendCommand("003A","R",Duty); //Set a status on the XNODE
  else
    xnode.SendCommand("003A","F",Duty); //Set a status on the XNODE
}

BLYNK_WRITE(2)
{
  Dir = param.asInt();
  if (Dir == 1)
    xnode.SendCommand("003A","R",Duty); //Set a status on the XNODE
  else
    xnode.SendCommand("003A","F",Duty); //Set a status on the XNODE
}

void ReadData(void) {
  float I = xnode.ReadAnswerToFloat("002A", "G");  //Saves the X-NODE current reading 
  Blynk.virtualWrite(V0, I);
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
