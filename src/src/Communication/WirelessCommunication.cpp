/**
 * Authouse.Communication.WirelessCommunication
 *   The wireless communication method for Authouse.
 *   @author pan93412
 *   @date 2020-12-15
 */
#include "WirelessCommunication.hpp"

/**
 * Get the instance of WirelessCommunication.
 */
WirelessCommunication* WirelessCommunication::getInstance() {
    // If we didn't create such an instance before.
    if (!instance) {
        instance = new WirelessCommunication();
    }

    return instance;
}

/**
 * Get the Wi-Fi mode.
 */
WIRELESS_MODE WirelessCommunication::getMode() {
    return this->conn->mode;
}

/**
 * Set the Wi-Fi mode.
 */
WirelessCommunication* WirelessCommunication::setMode(WIRELESS_MODE mode) {
    this->conn->mode = mode;
    return this;
}

/**
 * Get the SSID to connect to.
 */
std::string WirelessCommunication::getSSID() {
    return this->conn->ssid;
}

/**
 * Set the SSID to connect to.
 */
WirelessCommunication* WirelessCommunication::setSSID(std::string ssid) {
    this->conn->ssid = ssid;
    return this;
}

/**
 * Get the hotspot password to connect to.
 */
std::string WirelessCommunication::getPassword() {
    return this->conn->password;
}

/**
 * Set the hotspot password to connect to.
 */
WirelessCommunication* WirelessCommunication::setPassword(std::string password) {
    this->conn->password = password;
    return this;
}

/**
 * Connect to the hotspot, or create a AP of the specified
 * options.
 */
WirelessCommunication* WirelessCommunication::connect() {
    if (this->conn->mode == AP) {
        WiFi.softAP(this->conn->ssid.c_str(), this->conn->password.c_str());
    } else {
        WiFi.begin(this->conn->ssid.c_str(), this->conn->password.c_str());
    }
    return this;
}

/**
 * Disconnect the hotspot or deactivate the AP.
 */
WirelessCommunication* WirelessCommunication::disconnect() {
    WiFi.disconnect();
    return this;
}

/**
 * Have we connected to the network?
 */
bool WirelessCommunication::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}
