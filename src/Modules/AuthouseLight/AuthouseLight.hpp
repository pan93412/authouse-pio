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
    explicit AuthouseLight(uint8_t pin) noexcept;
    AuthouseLight *initiate() noexcept;
    AuthouseLight *activate() noexcept;
    AuthouseLight *deactivate() noexcept;
    AuthouseLight *setPin(uint8_t pin) noexcept;
    uint8_t getPin() const noexcept;
};

#endif