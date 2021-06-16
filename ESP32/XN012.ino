#include <X_NODE_esp32wroom.h>
X_NODE_esp32wroom xnode;

#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

unsigned long previousMillis = 0;
const long interval = 500;
char auth[] = "CPEmTfZ5rEtXeDgy2TyoA2Qf1jgow-_0"; //Enter your token here
int cont = 0;


String ValueLeds = "000000";

int flag = 0;
int L1;
int L2;
int L3;
int L4;
int L5;
int L6;
int pin_led = 12; //Pin built-in led 

void setup() {
  pinMode(pin_led, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  Blynk.begin(auth);
}

/*
  ---------------------------------------------------------------------------
  Funcion para enviar los comandos para la lectura de sensores
  Envia el ID del x-node y el comando mediante comunicación serial, retorna el
  valor regresado por la función ReadFloat.
  ---------------------------------------------------------------------------
*/

void setLed(void) {
  if (!L1 == 1)
    ValueLeds.setCharAt(0, '1');
  else
    ValueLeds.setCharAt(0, '0');
  if (!L2 == 1)
    ValueLeds.setCharAt(1, '1');
  else
    ValueLeds.setCharAt(1, '0');
  if (!L3 == 1)
    ValueLeds.setCharAt(2, '1');
  else
    ValueLeds.setCharAt(2, '0');
  if (!L4 == 1)
    ValueLeds.setCharAt(3, '1');
  else
    ValueLeds.setCharAt(3, '0');
  if (!L5 == 1)
    ValueLeds.setCharAt(4, '1');
  else
    ValueLeds.setCharAt(4, '0');
  if (!L6 == 1)
    ValueLeds.setCharAt(5, '1');
  else
    ValueLeds.setCharAt(5, '0');

  xnode.SendCommandString("012A", "G", ValueLeds);  //Set a status on the XNODE
 
  if (L1 == 1)
    ValueLeds.setCharAt(0, '1');
  else
    ValueLeds.setCharAt(0, '0');
  if (L2 == 1)
    ValueLeds.setCharAt(1, '1');
  else
    ValueLeds.setCharAt(1, '0');
  if (L3 == 1)
    ValueLeds.setCharAt(2, '1');
  else
    ValueLeds.setCharAt(2, '0');
  if (L4 == 1)
    ValueLeds.setCharAt(3, '1');
  else
    ValueLeds.setCharAt(3, '0');
  if (L5 == 1)
    ValueLeds.setCharAt(4, '1');
  else
    ValueLeds.setCharAt(4, '0');
  if (L6 == 1)
    ValueLeds.setCharAt(5, '1');
  else
    ValueLeds.setCharAt(5, '0');

  xnode.SendCommandString("012A", "R", ValueLeds);  //Set a status on the XNODE
}
BLYNK_WRITE(0) {
  L1 = param.asInt();
  setLed();
}

BLYNK_WRITE(1) {
  L2 = param.asInt();
  setLed();
}

BLYNK_WRITE(2) {
  L3 = param.asInt();
  setLed();
}

BLYNK_WRITE(3) {
  L4 = param.asInt();
  setLed();
}

BLYNK_WRITE(4) {
  L5 = param.asInt();
  setLed();
}

BLYNK_WRITE(5) {
  L6 = param.asInt();
  setLed();
}

void loop() {
  Blynk.run();
}
