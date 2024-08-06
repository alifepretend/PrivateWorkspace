#include "serialib.h"
#include <stdio.h>
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

//#if defined (_WIN32) || defined(_WIN64)
//    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
//    //also works for COM0 to COM9.
//    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
//#define SERIAL_PORT1 "\\\\.\\COM13"
//#endif
//#if defined (__linux__) || defined(__APPLE__)
//#define SERIAL_PORT1 "/dev/ttyACM0"
//#endif



string path = "F:/Projects_git/PrivateWorkspace/FunctionsCPP/documents/data1.txt";

const unsigned long int BAUD_RATE = 115200;

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

bool device_is_connected = false;
string line = "";


int main(int argc, char* argv[]) {
	if (argc == 3) {
		path = argv[2];
	}
	else {
		path = (string)argv[0];
		while (path[path.size() - 1] != '/') {
			path.pop_back();
		}
	}

	const char* port = "";
	if (argc > 1) {
		port = "\\\\.\\" + argv[1][0] + argv[1][1] + argv[1][2] + argv[1][3];
	} 
	const char* SERIAL_PORT = (const char*)port;


	IO::Serial serial(SERIAL_PORT, BAUD_RATE);

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
