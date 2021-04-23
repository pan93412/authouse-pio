/**
 * Authouse.Sensor.PM25.SHARP_GP2Y1014AU0F
 *   @brief The sensor class for SHARP GP2Y1014AU0F
 *   @author pan93412
 *   @date 2021-04-23
 */

#include "../PM25.hpp"
#ifndef AH_Sensor_Temperature_PM25_SHARP_GP2Y1014AU0F
#define AH_Sensor_Temperature_PM25_SHARP_GP2Y1014AU0F

struct SHGP2YSensorInfo : PM25Info {
    bool working = false;
    float raw;
};

class SHGP2YSensor : PM25<SHGP2YSensor> {
    private:
        int pin;
        SHGP2YSensorInfo* info;

    public:
        explicit SHGP2YSensor(uint8_t pin, SHGP2YSensorInfo *info): pin(pin) {
            this->info = info;
        }; 
        SHGP2YSensor* begin() noexcept override;
        SHGP2YSensor* update() noexcept override;
};

#endif
