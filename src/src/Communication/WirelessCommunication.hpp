/**
 * Authouse.Communication.WirelessCommunication
 *   The wireless communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-16
 */
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <string>
#ifndef AH_0180dc207ffeb5dca60615e22e34fe9f40683cc7
#define AH_0180dc207ffeb5dca60615e22e34fe9f40683cc7

/**
 * The wireless mode of WirelessCommunication
 */
enum WIRELESS_MODE {
    AP,
    STA,
};

struct ConnectionInfo {
    WIRELESS_MODE mode = STA;
    std::string ssid;
    std::string password;
};

/**
 * The wireless communication method for Authouse.
 * 
 * It is a singleton class: get the instance with `getInstance()`.
 */
class WirelessCommunication {
    private:
        static WirelessCommunication* instance;
        ConnectionInfo* conn = new ConnectionInfo();
        WirelessCommunication();
        ~WirelessCommunication() {
            delete conn;
        };

    public:
        static WirelessCommunication* getInstance();

        // mode
        WIRELESS_MODE getMode();
        WirelessCommunication* setMode(WIRELESS_MODE mode);
        // ssid
        std::string getSSID();
        WirelessCommunication* setSSID(std::string ssid);
        // pwd
        std::string getPassword();
        WirelessCommunication* setPassword(std::string password);

        WirelessCommunication* connect();
        WirelessCommunication* disconnect();

        bool isConnected();
};

#endif