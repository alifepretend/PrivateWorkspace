#include "serialib.h"
#include <stdio.h>

#if defined (_WIN32) || defined(_WIN64)
    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
    //also works for COM0 to COM9.
    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
#define SERIAL_PORT "\\\\.\\COM13"
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
#include <chrono>
#include <thread>

#define path "F:/Projects_git/PrivateWorkspace/FunctionsCPP/documents/data1.txt"

const unsigned long int BAUD_RATE = 115200;

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

bool device_is_connected = false;
string line = "";
IO::Serial serial(SERIAL_PORT, BAUD_RATE);

int main() {
	while (1) {
		if (serial.erroropening == 1) {
			int write = serial.receiveData(&line);

			if (write == 1) {

				IO().writeFile(line, path);
			}
		}
	}


	return 0;
}

// vector<vector<double>> valueTable = IO::parsecsv<double>(IO::readFile(PATH));

//sleep_for(milliseconds(100));
//sleep_until(system_clock::now() + seconds(1));
// Continuar daqui