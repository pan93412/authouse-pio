#include <Arduino.h>
#include <etl_profile.h>
#include "Modules/AuthouseLight/AuthouseLight.hpp"
#include "Modules/AuthouseLight/AuthouseLightPool.hpp"
#include "Communication/SerialCommunication.hpp"

AuthouseLightPool* pool;
SerialCommunication* serialCommunication;

void setup() {
  // put your setup code here, to run once:
  serialCommunication = SerialCommunication::getInstance();
  AuthouseLight* light1 = (new AuthouseLight(LED_BUILTIN))->initiate();
  pool = AuthouseLightPool::getInstance();
  pool->add(light1);
  serialCommunication->initiate();
}

void loop() {
  if (serialCommunication->isAvailableForReading()) {
    char read;
    serialCommunication->readRequestChar(&read);

    switch (read) {
      case 'e':
        serialCommunication->postMessage("Turn on all!");
        pool->turnOnAll();
        break;
      case 'd':
        serialCommunication->postMessage("Turn off all!");
        pool->turnOffAll();
        break;
    }
  }
}
