#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include <cstring> 
#include "Math.h"
#include "IO.h"
#include "serialib/serialib.h"

#define PATH "F:/Programming_Workspace/FunctionsCPP/documents/data1.txt"
#define BAUD_RATE 115200

int receiveData(string* line, serialib serial) {
	string data = "";

	while (serial.available() != 0) {
		char c;
		try {
			serial.readChar(&c);
			data += c;

			if (c == ';') {
				*line = data;
				return 1;
			}
		}
		catch (int e) {
			cout << "Erro ao tentar ler caractere." << endl;
			return 0;
		}
	}
}

using namespace std;


char PORT_C[4] = { 'C', 'O', 'M', '1' };

int main() {
	serialib serial;

	// Tenta iniciar conexão com porta serial.
	char errorOpening = serial.openDevice(PORT_C, BAUD_RATE);

	// Se conseguir abrir o dispositivo:
	if (errorOpening == 1) {
		printf("Successful connection to %s\n", PORT_C);
	}
	else {
		cout << "Erro ao tentar estabelecer conex�o com dispositivo." << endl;
	}



	string line = "";

	while (1) {
		receiveData(&line, serial);
		 // Continuar daqui
	}


	// vector<vector<double>> valueTable = IO::parsecsv<double>(IO::readFile(PATH));
	
	

	return 0;
}

// -> Medir tensão nos pinos dos NTCs e Pt100. -> Transformar em uma planilha no formato: 
//		*ntc-1*, *ntc-2*, *ntc-3*, *ntc-4*, *ntc-5*, *ntc-6*, *ntc-7*, *ntc-8*, *Pt100*, *time_ms*;
// -> Salvar arquivo na memória flash.
// -> Esperar 50ms.
// -> Repetir.
