/**
 * Authouse.Sensor.PM25
 *   @brief Authouse Sensor - PM2.5 Base
 *   @author pan93412
 *   @date 2021-4-23
 */

#include <DHT.h>
#include <stdint.h>
#ifndef AH_Sensor_PM25
#define AH_Sensor_PM25

struct PM25Info {
    float value;
};

template <class T>
class PM25 {
  public:
    virtual T* begin();
    virtual T* update();
};

#endif