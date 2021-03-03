/**
 * Authouse.Modules.AuthouseLight.AuthouseLight
 *   @brief Authouse Light.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include "AuthouseLight.hpp"

AuthouseLight::AuthouseLight(uint8_t pin) { this->pin = pin; }

AuthouseLight *AuthouseLight::initiate() {
    pinMode(this->pin, OUTPUT);
    return this;
}

AuthouseLight *AuthouseLight::activate() {
    digitalWrite(this->pin, HIGH);
    return this;
}

AuthouseLight *AuthouseLight::deactivate() {
    digitalWrite(this->pin, LOW);
    return this;
}

AuthouseLight *AuthouseLight::setPin(uint8_t pin) {
    this->pin = pin;
    return this;
}

uint8_t AuthouseLight::getPin() const { return this->pin; }
