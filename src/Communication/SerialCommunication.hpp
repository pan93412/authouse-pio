/**
 * Authouse.Communication.SerialCommunication
 *   @brief The serial communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-14
 */
#include <Arduino.h>
#include <stdint.h>
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
    uint64_t baud;

    explicit SerialCommunication(uint64_t baud) noexcept;

  public:
    SerialCommunication *initiate() noexcept;
    static SerialCommunication *getInstance() noexcept;
    SerialCommunication *setBaud(uint64_t baud) noexcept;
    SerialCommunication *postMessage(const String& message) noexcept; 
    SerialCommunication *readRequest(String *buf) noexcept;
    SerialCommunication *readRequest(String *buf, char until) noexcept;
    SerialCommunication *readRequestChar(int *buf) noexcept;
    static bool isAvailableForReading() noexcept;
    static bool isAvailableForWriting() noexcept;
};

#endif