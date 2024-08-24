#include "driver/ledc.h"
#include "Preferences.h"


Preferences preferences;
long number = 0;

void setup() {
  Serial.begin(115200);
  preferences.begin("test", false);
  number = preferences.getLong("number", 0);
  preferences.end();
  delay(10);




}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(number);
}

