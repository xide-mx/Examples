#ifndef X_NODE_esp32wroom_H
#define X_NODE_esp32wroom_H

#include <Arduino.h >

class X_NODE_esp32wroom
{
public:
    /*
    Function:
       void SendCommand (char* node, char* command, int value)
    Overview:
        Sends the commands to XNODEs trough serial port.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E.
        char* command: Commands for XNODEs; R, G, F, R.
        int value: Value of the command, e.g. 100, 30.
    Output:
        None.
    */
  void SendCommand (char* node, char* command, int value);

    /*
    Function:
       void SendCommandString (char* node, char* command, String value)
    Overview:
        Sends the commands to XNODEs trough serial port.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E.
        char* command: Commands for XNODEs; R, G, F, R.
        String value: Value of the command, e.g. 101010, 00001111.
    Output:
        None.
    */
  void SendCommandString (char* node, char* command, String value);

    /*
    Function:
        void SendAsk (char* node);
    Overview:
        Sends the ID and the command '?' trougth serial port.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E
    Output:
        None.
    */
  void SendAsk (char* node);

    /*
    Function:
        float ReadAnswerToFloat(char* node, char* command)
    Overview:
        Sends the commands to XNODEs trough serial ports, waits for the
        answer and proccesses the response.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E.
        char* command: Commands for XNODEs; e.g GH, GT, GP.
    Output:
        Float: Float from answer of the XNODE.
    */
  float ReadAnswerToFloat(char* node, char* command);

    /*
    Function:
        int ReadAnswerToInt(char* node, char* command)
    Overview:
        Sends the commands to XNODEs trough serial ports, waits for the
        answer and proccesses the response.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E.
        char* command: Commands for XNODEs; e.g GH, GT, GP.
    Output:
        int: Integer from answer of the XNODE.
    */
  int ReadAnswerToInt(char* node, char* command);

    /*
    Function:
        int ReadBinaryAnswer(char* node, char* command, char Answer[])
    Overview:
        Sends the commands to XNODEs trough serial ports, waits for the
        answer and save the characters int the array Answer[].
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E.
        char* command: Commands for XNODEs; R, G, F, R.
        char Answer[]: Array where characters are stored
    Output:
        None.
    */
  int ReadBinaryAnswer(char* node, char* command, char Answer[]); 


private:
  /*
    Function:
        void PrintCommand(char* node, char* command);
    Overview:
        Sends the ID and the command trougth serial port.
    Precondition:
        None.
    Input:
        char* node: XNODE´s model; e.g. 016A, 007E
        char* command: Commands for XNODEs; e.g GH, GT, GP.
    Output:
        None.
  */
  void PrintCommand(char* node, char* command);

  /*
    Function:
        int ReadBufferSerial(char* Buffer)
    Overview:
        Reads the serial port and store the characters in "Buffer".
        Returns the number of characters read.
    Precondition:
        None.
    Input:
        None.
    Output:
        Int: Number of characters read.
  */
  int ReadBufferSerial(char* Buffer);

  /*
    Function:
        bool CheckModel(char* Buffer, char* ID)
    Overview:
        Compares the ID and the XNODE´s answer, if match returns
        True, otherwise returns False
    Precondition:
        None.
    Input:
        char* ID: XNODE´s ID, model + index; e.g. 016A, 007E
        char* Buffer: XNODE´s Answer from serial port.
    Output:
        Bool: Comparison result.
  */
  bool CheckModel(char* Buffer, char* ID);

  /*
    Function:
        float StringtoFloat(char* Buffer)
    Overview:
        Cleans the XNODE´s ID from the answer and turn it in float.
    Precondition:
        The function CheackModel must returns TRUE.
    Input:
        char* Buffer: XNODE´s Answer from serial port.
    Output:
        Float: Float from answer of the XNODE.
  */
  float StringtoFloat(char* Buffer);

  /*
    Function:
        int StringtoFloat(char* Buffer)
    Overview:
        Cleans the XNODE´s ID from the answer and turn it in float.
    Precondition:
        The function CheackModel must returns TRUE.
    Input:
        char* Buffer: XNODE´s Answer from serial port.
    Output:
        int: Integer from answer of the XNODE.
  */
  int StringtoInt(char* Buffer) ;
  
};
#endif
