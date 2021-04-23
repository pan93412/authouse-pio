#include "Communication/SerialCommunication.hpp"
#include "Modules/AuthouseLight/AuthouseLight.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include "Sensor/Temperature/DHT11/DHT11.hpp"
#include "actions.hpp"
#include <Arduino.h>
#include <etl_profile.h>

const int DHT11_PORT = 4;
const int SHGP2Y_PORT = 2;

Dependencies *dependencies;

void setup() {
    // put your setup code here, to run once:
    dependencies = new Dependencies();
    dependencies->serialCommunication = SerialCommunication::getInstance();
    dependencies->pool = AuthouseLightPool::getInstance();
    dependencies->tempInfo = new TemperatureInfo();
    dependencies->dht11 = new DHT11Temp(DHT11_PORT, dependencies->tempInfo);
    dependencies->pm25Info = new SHGP2YSensorInfo();
    dependencies->pm25 = new SHGP2YSensor(SHGP2Y_PORT, dependencies->pm25Info);

    dependencies->pool->add((new AuthouseLight{LED_BUILTIN})->initiate());
    dependencies->serialCommunication->initiate();
    dependencies->dht11->begin();
    dependencies->pm25->begin();
}

void loop() {
    if (SerialCommunication::isAvailableForReading()) {
        int read = 0;
        dependencies->serialCommunication->readRequestChar(&read);

        action_loop(read, dependencies);
    }
}
