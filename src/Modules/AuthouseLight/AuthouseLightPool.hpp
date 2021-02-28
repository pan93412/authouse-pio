/**
 * Authouse.Modules.AuthouseLight.AuthouseLightPool
 *   Authouse Light Pool.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include <Arduino.h>
#include <vector>
#include "AuthouseLight.hpp"
#ifndef AH_Modules_AuthouseLight_AuthouseLightPool
#define AH_Modules_AuthouseLight_AuthouseLightPool

class AuthouseLightPool {
    private:
        std::vector<AuthouseLight*> lights;
        static AuthouseLightPool* instance;
        AuthouseLightPool();

        AuthouseLight** _query(int pin);

    public:
        static AuthouseLightPool* getInstance();

        AuthouseLightPool* add(AuthouseLight* authouseLight);
        AuthouseLightPool* add(int pin);
        AuthouseLightPool* remove(int pin, bool delete_detached_instance = true);
        AuthouseLight* query(int pin);
        
        AuthouseLightPool* turnOnAll();
        AuthouseLightPool* turnOffAll();
};

#endif