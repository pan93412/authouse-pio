/**
 * Authouse.Modules.AuthouseLight.AuthouseLight
 *   @brief Authouse Light.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include <Arduino.h>
#ifndef AH_Modules_AuthouseLight_AuthouseLight
#define AH_Modules_AuthouseLight_AuthouseLight

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