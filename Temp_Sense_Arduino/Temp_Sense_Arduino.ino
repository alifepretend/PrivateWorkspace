#include <vector>

#define ADC_RANGE 4096

using namespace std;

// 8 NTC, 1 Pt100
vector<int> ntc_pins = {34, 35, 32, 33, 25, 26, 27, 14, 12};
vector<int> pin_values = {0, 0, 0, 0, 0, 0, 0, 0, 0};
long int starting_time;
long int d_time;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  starting_time = millis();

  delay(1);

  
}

void loop() {
  int numberOfPins = ntc_pins.size();

  for(int i = 0; i < numberOfPins; i++) {
    pin_values[i] = analogRead(ntc_pins[i]);
  }
  
  printValues(pin_values, d_time);

  delay(100);
}


// Formato: "ntc_1","ntc_2","ntc_3","ntc_4","ntc_5","ntc_6","ntc_7","ntc_8","PT100","d_time";
static void printValues(vector<int> values, long int d_time) {
  int numberOfValues = values.size();

  for (int i = 0; i < numberOfValues; i++) {
    Serial.print("\"");
    Serial.print(values[i]);
    Serial.print("\",");

    if(i == (numberOfValues - 1)) {
      Serial.print("\"");
      d_time = millis() - starting_time;
      Serial.print(d_time);
      Serial.println("\";");
    }
  }
}
