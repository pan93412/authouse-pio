/**
 * Authouse.Modules.AuthouseLight.AuthouseLightPool
 *   Authouse Light Pool.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include <Arduino.h>
#include <vector>
#include "AuthouseLight.hpp"
#ifndef AH_8b37f5b3682544d7be873b4029019fa6cd371f36
#define AH_8b37f5b3682544d7be873b4029019fa6cd371f36

class AuthouseLightPool {
    private:
        std::vector<AuthouseLight*> lights;
        AuthouseLightPool* instance;
        AuthouseLightPool();

    public:
        AuthouseLightPool* getInstance();

        AuthouseLightPool* add(AuthouseLight* authouseLight);
        AuthouseLightPool* add(int pin);
        AuthouseLightPool* remove(int pin);
        AuthouseLight* query(int pin);
        
        AuthouseLightPool* turnOnAll();
        AuthouseLightPool* turnOffAll();
};

#endif