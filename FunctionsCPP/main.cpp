#include <iostream>
#include <vector>
#include <array>

#include "Math.h"
#include "IO.h"

#define PATH "F:/Programming_Workspace/FunctionsCPP/documents/data1.txt"

using namespace std;

int main() {
	vector<vector<double>> valueTable = IO::parsecsv<double>(IO::readFile(PATH));

	// Média da inclinação
	// double angularvalue = Math::linearRegression(valueTable, 1, 9.8);
	//cout << angularvalue << endl;

	return 0;
}

// -> Medir tensão nos pinos dos NTCs e Pt100. -> Transformar em uma planilha no formato: 
//		*ntc-1*, *ntc-2*, *ntc-3*, *ntc-4*, *ntc-5*, *ntc-6*, *ntc-7*, *ntc-8*, *Pt100*, *time_ms*;
// -> Salvar arquivo na memória flash.
// -> Esperar 50ms.
// -> Repetir.



