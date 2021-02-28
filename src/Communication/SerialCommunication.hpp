/**
 * Authouse.Communication.SerialCommunication
 *   @brief The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include <Arduino.h>
#ifndef AH_Communication_SerialCommunication
#define AH_Communication_SerialCommunication

/**
 * The serial communication method for Authouse.
 * 
 * It is a singleton class: get the instance with `getInstance()`.
 */
class SerialCommunication {
    private:
        static SerialCommunication* instance;
        unsigned long port;

        SerialCommunication(unsigned long port);

    public:
        SerialCommunication* initiate();
        static SerialCommunication* getInstance();
        SerialCommunication* setPort(unsigned long port);
        SerialCommunication* postMessage(String message);
        SerialCommunication* readRequest(String* buf);
        SerialCommunication* readRequest(String* buf, char until);
        SerialCommunication* readRequestChar(char* buf);
        bool isAvailableForReading();
        bool isAvailableForWriting();
};

#endif