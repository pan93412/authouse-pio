/**
 * Authouse.Sensor.Temperature.DHT11
 *   @brief Authouse Sensor - Temperature (DHT11)
 *   @author pan93412
 *   @date 2021-3-3
 */
#include "DHT11.hpp"

DHT11Temp *DHT11Temp::begin() {
    this->dht.begin();
    this->update();
    return this;
};

DHT11Temp *DHT11Temp::update() {
    this->info->humidity = this->dht.readHumidity();

    switch (this->mode) {
    case Celsius:
        this->info->temperature = this->readTempC();
        break;
    case Fahrenheit:
    default:
        this->info->temperature = this->readTempF();
    }

    return this;
};

DHT11Temp *DHT11Temp::tempMode(Mode mode) {
    this->mode = mode;
    return this;
};

float DHT11Temp::readTempF() { return this->dht.readTemperature(true); };

float DHT11Temp::readTempC() { return this->dht.readTemperature(false); };
