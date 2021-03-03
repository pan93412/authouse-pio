/**
 * Authouse.Modules.AuthouseLight.AuthouseLight
 *   @brief Authouse Light.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include "AuthouseLight.hpp"
#define THIS AuthouseLight

THIS::THIS(uint8_t pin) { this->pin = pin; }

THIS *THIS::initiate() {
    pinMode(this->pin, OUTPUT);
    return this;
}

THIS *THIS::activate() {
    digitalWrite(this->pin, HIGH);
    return this;
}

THIS *THIS::deactivate() {
    digitalWrite(this->pin, LOW);
    return this;
}

THIS *THIS::setPin(uint8_t pin) {
    this->pin = pin;
    return this;
}

uint8_t THIS::getPin() { return this->pin; }

#undef THIS
