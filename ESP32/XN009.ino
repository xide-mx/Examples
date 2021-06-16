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

int RL1;
int RL2;
int pin_led = 12; //Pin built-in led 

void setup() {
  pinMode(pin_led, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Blynk.begin(auth);
}

BLYNK_WRITE(0)
{
  RL1 = param.asInt();
  if ((RL1 == 1) and (RL2 == 1))
    xnode.SendCommand("009A", "S", 11); //Saves the X-NODE current reading 
  if ((RL1 == 1) and (RL2 == 0))
    xnode.SendCommand("009A", "S", 10); //Saves the X-NODE current reading 
  if ((RL1 == 0) and (RL2 == 1))
    xnode.SendCommand("009A", "S", 01); //Saves the X-NODE current reading 
  if ((RL1 == 0) and (RL2 == 0))
    xnode.SendCommand("009A", "S", 00); //Saves the X-NODE current reading 

}

BLYNK_WRITE(1) {
  RL2 = param.asInt();
  if ((RL1 == 1) and (RL2 == 1))
    xnode.SendCommand("009A", "S", 11); //Saves the X-NODE current reading 
  if ((RL1 == 1) and (RL2 == 0))
    xnode.SendCommand("009A", "S", 10); //Saves the X-NODE current reading 
  if ((RL1 == 0) and (RL2 == 1))
    xnode.SendCommand("009A", "S", 01); //Saves the X-NODE current reading 
  if ((RL1 == 0) and (RL2 == 0))
    xnode.SendCommand("009A", "S", 00); //Saves the X-NODE current reading 
}



void loop() {
  Blynk.run();
}
