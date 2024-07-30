#include "pins_arduino.h"
#include "stm32g4xx_hal_adc.h"
#include "stm32g4xx_hal_dac.h"
#include "stm32g4xx_hal_def.h"
#include <vector>

#define LL_ADC_RESOLUTION LL_ADC_RESOLUTION_12B
#define ADC_RANGE 4096

using namespace std;

DAC_HandleTypeDef hdac1;

int read;
// 8 NTC, 1 Pt100
vector<enum> ntc_pins = {A0, A1, A2, A3, A5, A6, A4, D6, D3};
vector<uint32_t> pin_values = {0, 0, 0, 0, 0, 0, 0, 0, 0};
long int starting_time;
long int d_time;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  analogReadResolution(12);
  starting_time = millis();

  delay(1);
  analogWrite(D14, 4095);
  
}

void loop() {
  readNtcAll(pins, &values, &d_time);

  delay(20);
}

static void readNtcAll(vector<enum> pins, vector<uint32_t> *values, long int *d_time) {
  int numberOfPins = pins.size();
  for(int i = 0; i < numberOfPins; i++) {
    *values[i] = digitalRead(pins[i]);
  }
  
  printValues(&values, &d_time);
}

// Formato: "ntc_1","ntc_2","ntc_3","ntc_4","ntc_5","ntc_6","ntc_7","ntc_8","PT100","d_time";
static void printValues(vector<uint32_t> values, long int *d_time) {
  int numberOfValues = values.size();

  for (int i = 0; i < numberOfValues; i++) {
    Serial.print("\"");
    Serial.print(values[i]);
    Serial.print("\",");

    if(i == (numberOfValues - 1)) {
      Serial.print("\"");
      *d_time = millis() - starting_time;
      Serial.print(*d_time);
      Serial.println("\";");
    }
  }
}


static float readVdd()
{
  return (1.20 * 4096.0 / analogRead(ADC_CHANNEL_VREFINT)); // ADC sample to V
  //return (1200 * 4096 / adc_read(ADC_CHANNEL_VREFINT)); // ADC sample to mV
}

static int32_t readVref()
{
  return (__LL_ADC_CALC_VREFANALOG_VOLTAGE(analogRead(AVREF), LL_ADC_RESOLUTION));
}

#ifdef ATEMP
static int32_t readTempSensor(int32_t VRef)
{
  return (__LL_ADC_CALC_TEMPERATURE(VRef, analogRead(ATEMP), LL_ADC_RESOLUTION));
}
#endif

