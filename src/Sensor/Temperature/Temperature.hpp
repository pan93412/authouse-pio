/**
 * Authouse.Sensor.Temperature
 *   @brief Authouse Sensor - Temperature Base
 *   @author pan93412
 *   @date 2021-3-3
 */

#include <DHT.h>
#include <stdint.h>
#ifndef AH_Sensor_Temperature
#define AH_Sensor_Temperature

struct TemperatureInfo {
    float humidity;
    float temperature;
};

enum Mode {
    Celsius,
    Fahrenheit,
};

template <class T>
class Temperature {
  public:
    virtual T* begin();
    virtual T* update();
    virtual T* tempMode(Mode mode);
};

#endif