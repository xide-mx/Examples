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
  if (RL1 == 1)
    xnode.SendCommand("018A","",1); //Set a status on the XNODE
  else
    xnode.SendCommand("018A","",0); //Set a status on the XNODE
}




void loop() {
  Blynk.run();
}
