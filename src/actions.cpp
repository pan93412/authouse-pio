/**
 * Authouse.Actions
 *   @brief Authouse actions
 *   @author pan93412
 *   @date 2021-3-12
 */
#include "actions.hpp"

inline void enable_authouse_light(AuthouseLightPool *pool, SerialCommunication *serialCommunication) {
    pool->turnOnAll();
    serialCommunication->postMessage("{\"light_enabled\": true}");
}

inline void disable_authouse_light(AuthouseLightPool *pool, SerialCommunication *serialCommunication) {
    pool->turnOffAll();
    serialCommunication->postMessage("{\"light_enabled\": false}");
}

inline void get_dht11_data(DHT11Temp* dht11, SerialCommunication *serialCommunication, TemperatureInfo* tempInfo) {
    dht11->update();
    serialCommunication->postMessageNoNl("{\"temperature\": ");
    serialCommunication->postMessageNoNl(String(tempInfo->temperature));
    serialCommunication->postMessageNoNl(", \"humidity\": ");
    serialCommunication->postMessageNoNl(String(tempInfo->humidity));
    serialCommunication->postMessage("}");
};

void test_input_output(SerialCommunication *serialCommunication) {
    String read;
    serialCommunication->postMessage("Start receiving inputs.");
    serialCommunication->readRequest(&read);
    serialCommunication->postMessage(read);
};

void get_pm25_data(SHGP2YSensor* sensor, SerialCommunication *serialCommunication, SHGP2YSensorInfo* data) {
    sensor->update();
    serialCommunication->postMessageNoNl("{\"working\": ");
    serialCommunication->postMessageNoNl(data->working ? "true" : "false");
    serialCommunication->postMessageNoNl(", \"value\": ");
    serialCommunication->postMessageNoNl(String(data->value));
    serialCommunication->postMessageNoNl(", \"raw_value\": ");
    serialCommunication->postMessageNoNl(String(data->raw));
    serialCommunication->postMessage("}");
}

void action_loop(int input, Dependencies* dependencies) {
    switch (input) { // received...
        case 'e':
            enable_authouse_light(dependencies->pool, dependencies->serialCommunication);
            break;
        case 'd':
            disable_authouse_light(dependencies->pool, dependencies->serialCommunication);
            break;
        case 't':
            get_dht11_data(dependencies->dht11, dependencies->serialCommunication, dependencies->tempInfo);
            break;
        case 'm':
            get_pm25_data(dependencies->pm25, dependencies->serialCommunication, dependencies->pm25Info);
            break;
        case 'p':
            test_input_output(dependencies->serialCommunication);
            break;
        default:
            break;
    }
}
