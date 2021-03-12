#include "Communication/SerialCommunication.hpp"
#include "Modules/AuthouseLight/AuthouseLight.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include "Sensor/Temperature/DHT11/DHT11.hpp"
#include "actions.hpp"
#include <Arduino.h>
#include <etl_profile.h>

Dependencies *dependencies;

void setup() {
    // put your setup code here, to run once:
    dependencies = new Dependencies();
    dependencies->serialCommunication = SerialCommunication::getInstance();
    dependencies->pool = AuthouseLightPool::getInstance();
    dependencies->tempInfo = new TemperatureInfo();
    dependencies->dht11 = new DHT11Temp(4, dependencies->tempInfo);

    dependencies->pool->add((new AuthouseLight{LED_BUILTIN})->initiate());
    dependencies->serialCommunication->initiate();
    dependencies->dht11->begin();
}

void loop() {
    if (SerialCommunication::isAvailableForReading()) {
        int read = 0;
        dependencies->serialCommunication->readRequestChar(&read);

        action_loop(read, dependencies);
    }
}
