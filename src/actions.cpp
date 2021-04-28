/**
 * Authouse.Actions
 *   @brief Authouse actions
 *   @author pan93412
 *   @date 2021-3-12
 */
#include "actions.hpp"

#define action(name) void (name)(Dependencies* dependencies)  // NOLINT
#define use(name) auto (name) = dependencies->name;  // NOLINT
#define use_custom(name, custom_name) auto (custom_name) = dependencies->name;  // NOLINT

/// Always enable this feature.
const bool ALWAYS_ENABLE = true;

// NOLINTNEXTLINE
#define def_action(key, action, flag) case (key): \
    if (flag) (action)(dependencies); \
    break;

/** FOR USER MODIFICATION - START **/

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
    serialCommunication->postMessageNoNl(R"({"temperature": ")");
    serialCommunication->postMessageNoNl(String(tempInfo->temperature));
    serialCommunication->postMessageNoNl(R"(", "humidity": ")");
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
    serialCommunication->postMessageNoNl(R"({"working": )");
    serialCommunication->postMessageNoNl(data->working ? "true" : "false");
    serialCommunication->postMessageNoNl(R"(, "value": ")");
    serialCommunication->postMessageNoNl(String(data->value));
    serialCommunication->postMessageNoNl(R"(", "raw_value": ")");
    serialCommunication->postMessageNoNl(String(data->raw));
    serialCommunication->postMessage("\"}");
}

void action_loop(int input, Dependencies* dependencies) {
    switch (input) { // received...

        // def_action('key', action_name, flag)
        //     key          the key to trigger the action
        //     action_name  the action name that is defined above.
        //     flag         make the action only available when flag == true
        //                  you can add the flag in configure.hpp, and
        //                  if you don't want this feature to be deactivated, use
        //                  ALWAYS_ENABLE.

        def_action('e', enable_authouse_light, LIGHT_SUPPORT)
        def_action('d', disable_authouse_light, LIGHT_SUPPORT)
        def_action('t', get_dht11_data, DHT11_SUPPORT)
        def_action('m', get_pm25_data, SHGP2Y_SUPPORT)
        def_action('p', test_input_output, ALWAYS_ENABLE)

/** FOR USER MODIFICATION - END **/

        default:
            break;
    }
}
