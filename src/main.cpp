#include <Arduino.h>
#include <vector>
#include "Modules/AuthouseLight/AuthouseLight.hpp"
// #include "Communication/SerialCommunication.hpp";
std::vector<AuthouseLight*> pool;

void setup() {
  // put your setup code here, to run once:
  AuthouseLight* light1 = (new AuthouseLight(32))->initiate();
  AuthouseLight* light2 = (new AuthouseLight(33))->initiate();
  AuthouseLight* light3 = (new AuthouseLight(25))->initiate();
  pool.push_back(light1);
  pool.push_back(light2);
  pool.push_back(light3);
}

void loop() {
  for (auto el: pool) {
    el->activate();
    delay(100);
  }

  for (auto el: pool) {
    el->deactivate();
    delay(100);
  }
}
