/**
 * @file /example1/main.cpp
 * @author Philippe Lucidarme
 * @date December 2019
 * @brief File containing example of serial port communication
 *
 * This example send a string through the serial device
 * The program expect receiving a string from the device
 * The received string is expected to terminated by a carriage return
 *
 * The following code has been tested with this Arduino Uno sketch
 * that return the uppercase character received on the serial device
 *
 * // Setup, initialize
 * void setup() {
 *      Serial.begin(115200);
 * }
 *
 * // Loop forever
 * void loop() {
 * // If serial data is pending, read and write the character uppercased
 * if (Serial.available())
 *      Serial.write( toupper (Serial.read()) );
 * }
 *
 * @see https://lucidar.me
 */


 // Serial library
#include "serialib.h"
#include <stdio.h>


#if defined (_WIN32) || defined(_WIN64)
    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
    //also works for COM0 to COM9.
    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
#define SERIAL_PORT "\\\\.\\COM1"
#endif
#if defined (__linux__) || defined(__APPLE__)
#define SERIAL_PORT "/dev/ttyACM0"
#endif

#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include <cstring> 
#include "math.h"
#include <fstream>
#include <sstream>
#include "IO.h"



#define path "f:/programming_workspace/functionscpp/documents/data1.txt"
#define SERIAL_PORT "\\\\.\\COM13"
const unsigned long int BAUD_RATE = 115200;

using namespace std;

string line = "";
IO::Serial serial(SERIAL_PORT, BAUD_RATE);

int main() {
	

	while (1) {
		serial.receiveData(&line);

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


