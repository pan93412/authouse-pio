#include "Communication/SerialCommunication.hpp"
#include "Modules/AuthouseLight/AuthouseLight.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include <Arduino.h>
#include <etl_profile.h>

AuthouseLight *light;
AuthouseLightPool *pool;
SerialCommunication *serialCommunication;

void setup() {
    // put your setup code here, to run once:
    serialCommunication = SerialCommunication::getInstance();
    light = new AuthouseLight{LED_BUILTIN};
    pool = AuthouseLightPool::getInstance();
    pool->add(light->initiate());
    serialCommunication->initiate();
}

void loop() {
    if (SerialCommunication::isAvailableForReading()) {
        int read = 0;
        serialCommunication->readRequestChar(&read);

        switch (read) {
        case 'e': {
            serialCommunication->postMessage("Turn on all!");
            pool->turnOnAll();
            break;
        }
        case 'd': {
            serialCommunication->postMessage("Turn off all!");
            pool->turnOffAll();
            break;
        }
        case 'p': {
            String read;

            serialCommunication->postMessage("Start receiving inputs.");
            serialCommunication->readRequest(&read);
            serialCommunication->postMessage(read);
            break;
        }
        default:
            break;
        }
    }
}
