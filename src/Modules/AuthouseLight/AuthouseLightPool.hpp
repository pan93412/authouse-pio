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

class AuthouseLightPool {
  private:
    etl::vector<AuthouseLight *, 10> lights;
    static AuthouseLightPool *instance;
    AuthouseLightPool();

    AuthouseLight **_query(int pin);

  public:
    static AuthouseLightPool *getInstance();

    AuthouseLightPool *add(AuthouseLight *authouseLight);
    AuthouseLightPool *add(int pin);
    AuthouseLightPool *remove(int pin, bool delete_detached_instance = true);
    AuthouseLight *query(int pin);

    AuthouseLightPool *turnOnAll();
    AuthouseLightPool *turnOffAll();
};

#endif