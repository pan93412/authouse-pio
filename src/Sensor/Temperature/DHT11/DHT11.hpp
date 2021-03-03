/**
 * Authouse.Sensor.Temperature.DHT11
 *   @brief Authouse Sensor - Temperature (DHT11)
 *   @author pan93412
 *   @date 2021-3-3
 */
#include "../Temperature.hpp"
#include <DHT.h>
#ifndef AH_Sensor_Temperature_DHT11
#define AH_Sensor_Temperature_DHT11

class DHT11Temp : Temperature<DHT11Temp> {
  private:
    DHT dht;
    TemperatureInfo *info;
    Mode mode;
    float readTempF();
    float readTempC();

  public:
    explicit DHT11Temp(uint8_t pin, TemperatureInfo *info) : dht(pin, DHT11), mode(Celsius) {
      this->info = info;
    };
    DHT11Temp *begin() noexcept override;
    DHT11Temp *update() noexcept override;
    DHT11Temp *tempMode(Mode mode) noexcept override;
};

#endif