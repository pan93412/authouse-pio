/**
 * Authouse.Sensor.PM25.SHARP_GP2Y1014AU0F
 *   @brief The sensor class for SHARP GP2Y1014AU0F
 *   @author pan93412
 *   @date 2021-04-23
 */

#include "SHGP2Y.hpp"

SHGP2YSensor* SHGP2YSensor::begin() {
    pinMode(this->pin, INPUT);
    this->update();
    return this;
};

SHGP2YSensor* SHGP2YSensor::update() {
    int val = analogRead(this->pin);
    // NOLINTNEXTLINE
    if (val > 36.455) {
        // NOLINTNEXTLINE
        this->info->value = (float(val / 1024) - 0.0356) * 120000 * 0.035;
        this->info->working = true;
    } else {
        this->info->working = false;
    }

    return this;
}
