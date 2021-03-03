/**
 * Authouse.Modules.AuthouseLight.AuthouseLightPool
 *   @brief Authouse Light Pool.
 *   @author pan93412
 *   @date 2021-2-28
 */

#include "AuthouseLightPool.hpp"

AuthouseLightPool *AuthouseLightPool::instance = nullptr;

AuthouseLightPool::AuthouseLightPool() = default;

AuthouseLightPool *AuthouseLightPool::getInstance() {  // NOLINT(readability-convert-member-functions-to-static)
    if (instance == nullptr) {
        instance = new AuthouseLightPool();
    }

    return instance;
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
AuthouseLightPool *AuthouseLightPool::add(AuthouseLight *authouseLight) {
    lights.push_back(authouseLight);
    return instance;
}

AuthouseLightPool *AuthouseLightPool::add(int pin) {
    auto *lightInstance = new AuthouseLight(pin);
    return this->add(lightInstance);
}

// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
AuthouseLight **AuthouseLightPool::_query(int pin) {
    for (auto *i = lights.begin(); i < lights.end(); i++) {
        if ((*i)->getPin() == pin) {
            return i;
        }
    }
    return nullptr;
}

AuthouseLight *AuthouseLightPool::query(int pin) {
    AuthouseLight **lightInstance = this->_query(pin);
    if (lightInstance != nullptr) {
        return *lightInstance;
    }
    return nullptr;
}

AuthouseLightPool *AuthouseLightPool::remove(int pin, bool delete_detached_instance /*=true*/) {
    AuthouseLight **lightInstance = this->_query(pin);
    if (lightInstance != nullptr) {
        lights.erase(lightInstance);
        if (*lightInstance != nullptr && delete_detached_instance) {
            delete *lightInstance;
        }
    }

    return this;
}

AuthouseLightPool *AuthouseLightPool::turnOnAll() {
    for (auto *i = lights.begin(); i < lights.end(); i++) {
        (*i)->activate();
    }

    return this;
}

AuthouseLightPool *AuthouseLightPool::turnOffAll() {
    for (auto *i = lights.begin(); i < lights.end(); i++) {
        (*i)->deactivate();
    }

    return this;
}

