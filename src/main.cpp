#include "Communication/SerialCommunication.hpp"
#include "Modules/AuthouseLight/AuthouseLight.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include "Sensor/Temperature/DHT11/DHT11.hpp"
#include "actions.hpp"
#include "configure.hpp"
#include <Arduino.h>
#include <etl_profile.h>

Dependencies *dependencies;

void setup() {
    // put your setup code here, to run once:
    dependencies = new Dependencies();

    // serial communication
    dependencies->serialCommunication = SerialCommunication::getInstance();
    dependencies->serialCommunication->initiate();

    // light pool
    if (LIGHT_SUPPORT) {
        dependencies->pool = AuthouseLightPool::getInstance();
        dependencies->pool->add((new AuthouseLight{LED_BUILTIN})->initiate());
    }

    // DHT11
    if (DHT11_SUPPORT) {
        dependencies->tempInfo = new TemperatureInfo();
        dependencies->dht11 = new DHT11Temp(DHT11_PORT, dependencies->tempInfo);
        dependencies->dht11->begin();    
    }

    // PM2.5
    if (SHGP2Y_SUPPORT) {
        dependencies->pm25Info = new SHGP2YSensorInfo();
        dependencies->pm25 = new SHGP2YSensor(SHGP2Y_PORT, dependencies->pm25Info);
        dependencies->pm25->begin();
    }
}

void loop() {
    if (SerialCommunication::isAvailableForReading()) {
        int read = 0;
        dependencies->serialCommunication->readRequestChar(&read);

        action_loop(read, dependencies);
    }
}
