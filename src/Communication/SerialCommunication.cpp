/**
 * Authouse.Communication.SerialCommunication
 *   @brief The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include "SerialCommunication.hpp"
#define THIS SerialCommunication

THIS* THIS::instance = nullptr;

THIS::THIS(unsigned long port) {
    this->port = port;
}

/**
 * Initiate the serial connection.
 */
THIS* THIS::initiate() {
    Serial.begin(this->port);
    return this;
}

/**
 * Get the instance of THIS.
 * 
 * Note that the default port of THIS is
 * 9600. To change, use `THIS::setPort()`.
 */
THIS* THIS::getInstance() {
    // If we didn't create such an instance before.
    if (!instance) {
        instance = new THIS(9600);
    }

    return instance;
}

/**
 * Set the port of the serial to send.
 */
THIS* THIS::setPort(unsigned long port) {
    this->port = port;
    return this;
};

/**
 * Post message ended with '\n' to the specified serial.
 */
THIS* THIS::postMessage(String message) {
    Serial.println(message);
    Serial.flush();
    return this;
}

/**
 * Read messages from the specified serial.
 */
THIS* THIS::readRequest(String* buf) {
    *buf = Serial.readString();
    return this;
}

/**
 * Read messages until reached <until> from the specified serial.
 */
THIS* THIS::readRequest(String* buf, char until) {
    *buf = Serial.readStringUntil(until);
    return this;
}

/**
 * Read a char from the specified serial.
 */
THIS* THIS::readRequestChar(char* buf) {
    *buf = Serial.read();
    return this;
}

bool THIS::isAvailableForReading() {
    return Serial.available();
}

bool THIS::isAvailableForWriting() {
    return Serial.availableForWrite();
}

#undef THIS
