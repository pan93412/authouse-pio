/**
 * Authouse.Actions
 *   @brief Authouse actions
 *   @author pan93412
 *   @date 2021-3-12
 */

#include "Communication/SerialCommunication.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include "Sensor/PM25/SHARP_GP2Y1014AU0F/SHGP2Y.hpp"
#include "Sensor/Temperature/DHT11/DHT11.hpp"
#include "configure.hpp"

#ifndef AH_Actions
#define AH_Actions

struct Dependencies {
    AuthouseLightPool *pool;
    SerialCommunication *serialCommunication;
    DHT11Temp* dht11;
    TemperatureInfo* tempInfo;
    SHGP2YSensor* pm25;
    SHGP2YSensorInfo* pm25Info;
};

// Do not modify the following declarations.
void action_loop(int input, Dependencies* dependencies);

#endif
