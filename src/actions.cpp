/**
 * Authouse.Actions
 *   @brief Authouse actions
 *   @author pan93412
 *   @date 2021-3-12
 */
#include "actions.hpp"

#define use(name) auto name = dependencies->name;

action(enable_authouse_light) {
    use(pool)
    use(serialCommunication)

    pool->turnOnAll();
    serialCommunication->postMessage("{\"light_enabled\": true}");
}

action(disable_authouse_light) {
    use(pool)
    use(serialCommunication)

    pool->turnOffAll();
    serialCommunication->postMessage("{\"light_enabled\": false}");
}

action(get_dht11_data) {
    use(dht11)
    use(serialCommunication)
    use(tempInfo)

    dht11->update();
    serialCommunication->postMessageNoNl("{\"temperature\": \"");
    serialCommunication->postMessageNoNl(String(tempInfo->temperature));
    serialCommunication->postMessageNoNl("\", \"humidity\": \"");
    serialCommunication->postMessageNoNl(String(tempInfo->humidity));
    serialCommunication->postMessage("\"}");
};

action(test_input_output) {
    use(serialCommunication)

    String read;
    serialCommunication->postMessage("Start receiving inputs.");
    serialCommunication->readRequest(&read);
    serialCommunication->postMessage(read);
};

action(get_pm25_data) {
    use_custom(pm25, sensor)
    use_custom(pm25Info, data)
    use(serialCommunication)

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
            enable_authouse_light(dependencies);
            break;
        case 'd':
            disable_authouse_light(dependencies);
            break;
        case 't':
            get_dht11_data(dependencies);
            break;
        case 'm':
            get_pm25_data(dependencies);
            break;
        case 'p':
            test_input_output(dependencies->serialCommunication);
            break;
        default:
            break;
    }
}
