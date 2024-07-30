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
vector<enum> ntc_pins = {A0, A1, A2, A3, A5, A6, A4, }

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  analogReadResolution(12);

  delay(1);
  analogWrite(D14, 4095);
  
}

void loop() {
  Serial.println(readTempSensor(readVref()));
  Serial.println((uint32_t)*TEMPSENSOR_CAL1_ADDR);
  Serial.println((uint32_t)*TEMPSENSOR_CAL2_ADDR);
  Serial.println(analogRead(ATEMP));
  Serial.println(readVref());

  delay(500);
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

