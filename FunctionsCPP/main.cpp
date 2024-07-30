#include <iostream>
#include <vector>
#include <array>

#include "Math.h"
#include "IO.h"

#define PATH "F:/Programming_Workspace/FunctionsCPP/documents/data1.txt"
#define PORT "COM1" 
#define BAUD_RATE 115200

using namespace std;
using namespace IO;

int main() {
	SerialManager serial(PORT, BAUD_RATE) // Continuar daqui



	vector<vector<double>> valueTable = IO::parsecsv<double>(IO::readFile(PATH));
	
	

	return 0;
}

// -> Medir tensão nos pinos dos NTCs e Pt100. -> Transformar em uma planilha no formato: 
//		*ntc-1*, *ntc-2*, *ntc-3*, *ntc-4*, *ntc-5*, *ntc-6*, *ntc-7*, *ntc-8*, *Pt100*, *time_ms*;
// -> Salvar arquivo na memória flash.
// -> Esperar 50ms.
// -> Repetir.



