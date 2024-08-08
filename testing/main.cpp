#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstring>
#include "serialib.h"
#include <stdio.h>
using namespace std;

#define PATH "./data.txt"
#define BAUD_RATE 115200

serialib serial;

int main() {
	serial.openDevice
	return 1;
}


int receiveData(string* line, serialib* serial) {
	*line = "";
	
	

	while(serial->available() != 0) {
		char c;

		try {
			serial->readChar(&c);
			*line += c;

			if (c == ';') {
				return 1;
			}
		} catch (int e) {
			cout << "Erro ao tentar ler caractere." << endl;
			return 0;
		}
	}
}
