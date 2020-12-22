/**
 * Authouse.Communication.SerialCommunication
 *   The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include "SerialCommunication.hpp"

SerialCommunication::SerialCommunication(int port) {
    this->port = port;
}

/**
 * Initiate the serial connection.
 */
SerialCommunication* SerialCommunication::initiate() {
    Serial.begin(this->port);
    return this;
}

/**
 * Get the instance of SerialCommunication.
 * 
 * Note that the default port of SerialCommunication is
 * 115200. To change, use `SerialCommunication::setPort()`.
 */
SerialCommunication* SerialCommunication::getInstance() {
    // If we didn't create such an instance before.
    if (!instance) {
        instance = new SerialCommunication(115200);
    }

    return instance;
}

/**
 * Set the port of the serial to send.
 */
SerialCommunication* SerialCommunication::setPort(int port) {
    this->port = port;
    return this;
};

/**
 * Post message ended with '\n' to the specified serial.
 */
SerialCommunication* SerialCommunication::postMessage(std::string message) {
    if (isAvailable()) Serial.println(message.c_str());
    return this;
}

/**
 * Is the serial available?
 */
bool SerialCommunication::isAvailable() {
    return Serial.available() && Serial.availableForWrite();
}
