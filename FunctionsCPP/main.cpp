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

string path = "F:/Projects_git/PrivateWorkspace/FunctionsCPP/documents/data1.txt";

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

string line = "";


int main() {
	vector<vector<double>> adc_esp = IO().parsecsv(IO().readFile("F:\\Projects_git\\PrivateWorkspace\\FunctionsCPP\\adc_esp.txt"));
	vector<vector<double>> tensao_arduino = IO().parsecsv(IO().readFile("F:\\Projects_git\\PrivateWorkspace\\FunctionsCPP\\tensao_arduino.txt"));
	cout << tensao_arduino.size() << endl;
	cout << adc_esp.size() << endl;
	vector<vector<double>> approximation = IO().approximateGivenTheTime(&tensao_arduino, adc_esp);
	cout << approximation.size();


	for (int i = 0; i < approximation.size(); i++) {
		for (int j = 0; j < approximation[i].size(); j++) {
			cout << approximation[i][j];
		}
		cout << endl;
	}

	return 0;
}
