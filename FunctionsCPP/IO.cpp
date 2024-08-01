#include "io.h"

//class SerialManager {
//private:
//	
//public:
//	serialib serial;
//	// Inicia a porta serial.
//	SerialManager(char* serial_port, long int baud_rate) {
//
//		// Tenta iniciar conexão com porta serial.
//		char errorOpening = serial.openDevice(serial_port, baud_rate);
//
//		// Se conseguir abrir o dispositivo:
//		if (errorOpening == 1) {
//			printf("Successful connection to %s\n", serial_port);
//		}
//		else {
//			cout << "Erro ao tentar estabelecer conexão com dispositivo." << endl;
//		}
//	}
//	
//	// Retorna 1 no caso de sucesso, 0 caso falhe.
//	int  receiveData(string* line) {
//		string data = "";
//
//		while(serial.available() != 0) {
//			char c;
//			try {
//				serial.readChar(&c);
//				data += c;
//				
//				if(c == ';') {
//					*line = data;
//					return 1;
//				}
//			} catch (int e) {
//				cout << "Erro ao tentar ler caractere." << endl;
//				return 0;
//			}
//		}
//	}
//};

