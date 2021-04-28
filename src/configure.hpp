/**
 * Authouse.Configure
 *   @brief Configure Authouse.
 *   @author pan93412
 *   @date 2021-4-23
 */

#ifndef AH_Configure
#define AH_Configure

/**
 * Support flags.
 * To remove one of a feature, change true to false.
 */

/// Enable Authouse Light support.
const bool LIGHT_SUPPORT = true;
/// Enable DHT11 sensor support.
const bool DHT11_SUPPORT = true;
/// Enable SHARP GP2Y1014AU0F sensor support.
const bool SHGP2Y_SUPPORT = true;

/// The serial port that DHT11 used.
const int DHT11_PORT = 4;

/// The serial port that SHARP GP2Y1014AU0F used.
const int SHGP2Y_PORT = 2;

/// The lightbulb to be used on Authouse Light.
const uint8_t LIGHT_PORT[] = { LED_BUILTIN, 13 };

/// How many lightbulb will be used on Authouse Light?
/// Usually be the entries count of LIGHT_PORT[]
const uint8_t LIGHT_PORT_NUMBER = 2;

#endif
