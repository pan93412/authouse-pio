/**
 * Authouse.Sensor.Temperature.DHT11
 *   @brief Authouse Sensor - Temperature (DHT11) (Dumped)
 *   @author pan93412
 *   @date 2021-3-3
 */
#include "DHT11.hpp"

DHT11Temp *DHT11Temp::begin() {
    return this;
};

DHT11Temp *DHT11Temp::update() {
    this->info->humidity = 56.00;

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

float DHT11Temp::readTempF() { return 80.60; };

float DHT11Temp::readTempC() { return 27.00; };
