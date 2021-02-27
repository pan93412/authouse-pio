/**
 * Authouse.Modules.AuthouseLight.AuthouseLight
 *   Authouse Light.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include <Arduino.h>
#ifndef AH_997d47f6e66977186f9ec136f0234267c4e9281e
#define AH_997d47f6e66977186f9ec136f0234267c4e9281e

class AuthouseLight {
    private:
        uint8_t pin;

    public:
        AuthouseLight(uint8_t pin = 0);
        AuthouseLight* initiate();
        AuthouseLight* activate();
        AuthouseLight* deactivate();
        AuthouseLight* setPin(uint8_t pin);
        uint8_t getPin();
};

#endif