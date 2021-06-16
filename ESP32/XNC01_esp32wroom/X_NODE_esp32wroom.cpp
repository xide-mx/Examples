#include "X_NODE_esp32wroom.h"

void X_NODE_esp32wroom:: SendCommand (char* node, char* command, int value) {
  Serial2.print("XN");
  Serial2.print(node);
  Serial2.print("+S");
  Serial2.print(command);
  Serial2.print("=");
  Serial2.println(value);
}

void X_NODE_esp32wroom:: SendCommandString (char* node, char* command, String value) {
  Serial2.print("XN");
  Serial2.print(node);
  Serial2.print("+S");
  Serial2.print(command);
  Serial2.print("=");
  Serial2.println(value);
}

void X_NODE_esp32wroom::SendAsk (char* node)
{
  Serial2.print("XN");
  Serial2.print(node);
  Serial2.println("?");
}

float X_NODE_esp32wroom::ReadAnswerToFloat(char* node, char* command) {
  delay(100);
  char Buffer[20];
  PrintCommand(node, command);
  int NumBytes = ReadBufferSerial(Buffer);
  if (CheckModel(Buffer, node)) {
    return (StringtoFloat(Buffer));
  } else {
    return 0;
  }
}

int X_NODE_esp32wroom:: ReadAnswerToInt(char* node, char* command) {
  char Buffer[20];
  PrintCommand(node, command);
  ReadBufferSerial(Buffer);
  if (CheckModel(Buffer, node)) {
    return (StringtoInt(Buffer));
  } else {
    return 0;
  }
}

int X_NODE_esp32wroom:: ReadBinaryAnswer(char* node, char* command, char Answer[]) {
  PrintCommand(node, command);
  char Buffer[20];
  ReadBufferSerial(Buffer);
  if (CheckModel(Buffer, node)) {
    memcpy(Answer, &Buffer[7], strlen(Buffer)+1 );

    return (1);
  } else {
    return 0;
  }
}


void X_NODE_esp32wroom::PrintCommand(char* node, char* command) {
  if (Serial2.available()) {
    while (Serial2.available() > 0) {
      char c = Serial2.read();
    }
  }
  delay(10);
  Serial2.print("XN");
  Serial2.print(node);
  Serial2.print("+");
  Serial2.print(command);
  Serial2.print("\r\n");
}

int X_NODE_esp32wroom::ReadBufferSerial(char* Buffer) {
  int ContBuff = 0;
  uint32_t CounterTimer = 400000000;
  do {
    if (Serial2.available()) {
      char c = Serial2.read();
      CounterTimer = 400000000;
      if (c == '\n' || c == '\r') {
        Buffer[ContBuff] = '\0';
        return ContBuff;
      } else {
        Buffer[ContBuff++] = c;
      }
    }
    CounterTimer--;
  } while (CounterTimer > 0);

  while (Serial2.available() > 0) {
    char c = Serial2.read();
  }
  return ContBuff;
}

bool X_NODE_esp32wroom:: CheckModel(char* Buffer, char* ID) {
  char ModeloID[10];
  sprintf(ModeloID, "XN%s=", ID);
  if (!(strncmp(Buffer, ModeloID, 7))) {
    return true;
  } else {
    return false;
  }
}

float X_NODE_esp32wroom::StringtoFloat(char* Buffer) {
  String Buffer1 = Buffer;
  String NumberInString = Buffer1.substring(7);
  return (NumberInString.toFloat());
}

int X_NODE_esp32wroom::StringtoInt(char* Buffer) {
  String Buffer1 = Buffer;
  String NumberInString = Buffer1.substring(7);
  return (NumberInString.toInt());
}
