#include "Preferences.h"
#include <vector>

class Calibration {
private:
	void loadCalibrationFromMemory();

	// Armazena a função do adc e os offsets dos pinos.
	// { intervalo, constantes da função (em ordem decrescente do expoente)}
	struct {
		struct {
			vector<>
		} pin_26;
	} adc_pins_functions;

public:
	Preferences preferences;


};