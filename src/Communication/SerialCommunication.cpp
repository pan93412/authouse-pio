/**
 * Authouse.Communication.SerialCommunication
 *   @brief The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include "SerialCommunication.hpp"

const uint64_t DEFAULT_BAUD = 9600;

SerialCommunication *SerialCommunication::instance = nullptr;

SerialCommunication::SerialCommunication(uint64_t baud) { this->baud = baud; }

/**
 * Initiate the serial connection.
 */
SerialCommunication *SerialCommunication::initiate() {
    Serial.begin(this->baud);
    return this;
}

/**
 * Get the instance of SerialCommunication.
 *
 * Note that the default baud is @see DEFAULT_BAUD.
 * To change, use `SerialCommunication::setBaud()`.
 */
SerialCommunication *SerialCommunication::getInstance() { // NOLINT(readability-convert-member-functions-to-static)
    // If we didn't create such an instance before.
    if (instance == nullptr) {
        instance = new SerialCommunication(DEFAULT_BAUD);
    }

    return instance;
}

/**
 * Set the baud of the serial to send.
 */
SerialCommunication *SerialCommunication::setBaud(uint64_t baud) {
    this->baud = baud;
    return this;
};

/**
 * Post message ended with '\n' to the specified serial.
 */
SerialCommunication *SerialCommunication::postMessage(const String& message) {
    Serial.println(message);
    Serial.flush();
    return this;
};

/**
 * Post message ended with '\n' to the specified serial.
 */
SerialCommunication *SerialCommunication::postMessageNoNl(const String& message) {
    Serial.print(message);
    Serial.flush();
    return this;
}

/**
 * Read messages from the specified serial.
 */
SerialCommunication *SerialCommunication::readRequest(String *buf) {
    *buf = Serial.readString();
    return this;
}

/**
 * Read messages until reached <until> from the specified serial.
 */
SerialCommunication *SerialCommunication::readRequest(String *buf, char until) {
    *buf = Serial.readStringUntil(until);
    return this;
}

/**
 * Read a char from the specified serial.
 */
SerialCommunication *SerialCommunication::readRequestChar(int *buf) {
    *buf = Serial.read();
    return this;
}

bool SerialCommunication::isAvailableForReading() { return Serial.available() > 0; }  // NOLINT(readability-convert-member-functions-to-static)

bool SerialCommunication::isAvailableForWriting() { return Serial.availableForWrite() > 0; }  // NOLINT(readability-convert-member-functions-to-static)
