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
  serialCommunication->postMessage("Turn on all!");
  pool->turnOnAll();
  delay(700);
  serialCommunication->postMessage("Turn off all!");
  pool->turnOffAll();
  delay(700);
}
