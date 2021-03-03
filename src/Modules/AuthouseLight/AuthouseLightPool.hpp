/**
 * Authouse.Modules.AuthouseLight.AuthouseLightPool
 *   @brief Authouse Light Pool.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include "AuthouseLight.hpp"
#include <Arduino.h>
#include <etl/vector.h>
#ifndef AH_Modules_AuthouseLight_AuthouseLightPool
#define AH_Modules_AuthouseLight_AuthouseLightPool

const int LIGHTS_SIZE = 10;

class AuthouseLightPool {
  private:
    etl::vector<AuthouseLight *, LIGHTS_SIZE> lights;
    static AuthouseLightPool *instance;
    AuthouseLightPool();

    AuthouseLight **_query(int pin) noexcept;

  public:
    static AuthouseLightPool *getInstance() noexcept;

    AuthouseLightPool *add(AuthouseLight *authouseLight) noexcept;
    AuthouseLightPool *add(int pin) noexcept;
    AuthouseLightPool *remove(int pin, bool delete_detached_instance = true) noexcept;
    AuthouseLight *query(int pin) noexcept;

    AuthouseLightPool *turnOnAll() noexcept;
    AuthouseLightPool *turnOffAll() noexcept;
};

#endif