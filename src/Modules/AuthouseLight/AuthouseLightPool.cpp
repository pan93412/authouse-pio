#include "AuthouseLightPool.hpp"
#define THIS AuthouseLightPool

THIS* THIS::instance = nullptr;

THIS::THIS() {}

THIS* THIS::getInstance() {
    if (!instance) {
        instance = new AuthouseLightPool();
    }

    return instance;
}

THIS* THIS::add(AuthouseLight* authouseLight) {
    lights.push_back(authouseLight);
    return instance;
}

THIS* THIS::add(int pin) {
    AuthouseLight* lightInstance = new AuthouseLight(pin);
    return this->add(lightInstance);
}

AuthouseLight** THIS::_query(int pin) {
    for (auto i = lights.begin(); i < lights.end(); i++) {
        if ((*i)->getPin() == pin) return i;
    }
    return nullptr;
}

AuthouseLight* THIS::query(int pin) {
    AuthouseLight** lightInstance = this->_query(pin);
    if (lightInstance) return *lightInstance;
    return nullptr;
}

THIS* THIS::remove(int pin, bool delete_detached_instance /*=true*/) {
    AuthouseLight** lightInstance = this->_query(pin);
    if (lightInstance != nullptr) {
        lights.erase(lightInstance);
        if (*lightInstance != nullptr && delete_detached_instance) delete *lightInstance;
    }

    return this;
}

THIS* THIS::turnOnAll() {
    for (auto i = lights.begin(); i < lights.end(); i++) {
        (*i)->activate();
    }

    return this;
}

THIS* THIS::turnOffAll() {
    for (auto i = lights.begin(); i < lights.end(); i++) {
        (*i)->deactivate();
    }

    return this;
}

#undef THIS
