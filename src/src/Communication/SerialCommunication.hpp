/**
 * Authouse.Communication.SerialCommunication
 *   The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include <Arduino.h>
#include <string>
#ifndef AH_185326bdfe0235150e5c6cc7116a4b311dc64228
#define AH_185326bdfe0235150e5c6cc7116a4b311dc64228

/**
 * The serial communication method for Authouse.
 * 
 * It is a singleton class: get the instance with `getInstance()`.
 */
class SerialCommunication {
    private:
        static SerialCommunication* instance;
        int port;

        SerialCommunication(int port);

    public:
        SerialCommunication* initiate();
        static SerialCommunication* getInstance();
        SerialCommunication* setPort(int port);
        SerialCommunication* postMessage(std::string message);
        bool isAvailable();
};

#endif