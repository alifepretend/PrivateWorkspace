
#include <vector>

#define ADC_RANGE 4096
#define ADC_PIN 26

using namespace std;

vector<int> pin_values = {0};
long int starting_time;
long int d_time;
long long sum = 0;

vector<int> last_10_measurements;
int last_10_sum = 0;

class Calibration {
public:
  double signalToVoltage(int signal) {
        float voltage = 0;
    if (signal <= 106) {
      voltage = -2.20612720612721 / (10*10*10*10*10) * signal * signal + 0.00401723276723277 * signal + 0.0420537795537795;
    } else if (signal <= 3161) {
      voltage = 0.000801963993453355 * signal + 0.134991816693945;
    } else if (signal <= 3950) {
      voltage = -1.9786426776347 / (10*10*10*10*10*10*10) * signal * signal + 0.00196468074215982 * signal - 1.56331169375177;
    } else {
      voltage = 9.22233300100278 / (10*10*10*10*10*10) * signal * signal - 0.0729341466600668 * signal + 147.309613659118;
    }

    return voltage;
}
};

int vReadAverage(int n_samples = 1000) {
  for (int i = 0; i < n_samples; i++) {
    sum += analogRead(ADC_PIN);

  }
  int average = (int)((double)sum/n_samples);
  sum = 0;
  return average;
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  starting_time = millis();

  pinMode(26, INPUT);
  delay(1);
}

void loop() {
  int average = vReadAverage();

  last_10_measurements.push_back(average);
  last_10_sum += average;
  if(last_10_measurements.size() > 10) {
    last_10_sum -= last_10_measurements[0];
    last_10_measurements.erase(last_10_measurements.begin());
  }
  int last_10_average = last_10_sum/last_10_measurements.size();
  Serial.print(last_10_average);
  Serial.println(";");
  Calibration calibration;
  float voltage = calibration.signalToVoltage(last_10_average);
  // if (last_10_average <= 106) {
  //   voltage = -2.20612720612721 / (10*10*10*10*10) * last_10_average * last_10_average + 0.00401723276723277 * last_10_average + 0.0420537795537795;
  // } else if (last_10_average <= 3161) {
  //   voltage = 0.000801963993453355 * last_10_average + 0.134991816693945;
  // } else if (last_10_average <= 3950) {
  //   voltage = -1.9786426776347 / (10*10*10*10*10*10*10) * last_10_average * last_10_average + 0.00196468074215982 * last_10_average - 1.56331169375177;
  // } else {
  //   voltage = 9.22233300100278 / (10*10*10*10*10*10) * last_10_average * last_10_average - 0.0729341466600668 * last_10_average + 147.309613659118;
  // }
  
  Serial.println(voltage);
}



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



