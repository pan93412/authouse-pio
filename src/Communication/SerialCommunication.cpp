/**
 * Authouse.Communication.SerialCommunication
 *   The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include "SerialCommunication.hpp"

SerialCommunication* SerialCommunication::instance = nullptr;

SerialCommunication::SerialCommunication(unsigned long port) {
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
 * 9600. To change, use `SerialCommunication::setPort()`.
 */
SerialCommunication* SerialCommunication::getInstance() {
    // If we didn't create such an instance before.
    if (!instance) {
        instance = new SerialCommunication(9600);
    }

    return instance;
}

/**
 * Set the port of the serial to send.
 */
SerialCommunication* SerialCommunication::setPort(unsigned long port) {
    this->port = port;
    return this;
};

/**
 * Post message ended with '\n' to the specified serial.
 */
SerialCommunication* SerialCommunication::postMessage(String message) {
    Serial.println(message);
    Serial.flush();
    return this;
}

/**
 * Read messages from the specified serial.
 */
SerialCommunication* SerialCommunication::readRequest(String* buf) {
    *buf = Serial.readString();
    return this;
}

/**
 * Read messages until reached <until> from the specified serial.
 */
SerialCommunication* SerialCommunication::readRequest(String* buf, char until) {
    *buf = Serial.readStringUntil(until);
    return this;
}