#include <stdio.h>
#include <iostream>
#include <vector>
#include <string> 
#include <array>
#include <cstring> 
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include "IO.h"
#include "Math.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

string path = "F:/Projects_git/PrivateWorkspace/FunctionsCPP/approximation.txt";


int main() {
	vector<vector<double>> adc_esp = IO().parsecsv(IO().readFile("F:\\Projects_git\\PrivateWorkspace\\FunctionsCPP\\adc_esp.txt"));
	vector<vector<double>> tensao_arduino = IO().parsecsv(IO().readFile("F:\\Projects_git\\PrivateWorkspace\\FunctionsCPP\\tensao_arduino.txt"));

	cout << tensao_arduino.size() << endl;
	cout << adc_esp.size() << endl;
	
	vector<vector<double>> approximation = IO().approximateGivenTheTime(&tensao_arduino, adc_esp);
	cout << approximation.size();

	

	for (int i = 0; i < approximation.size(); i++) {
		string line = "";
		line += to_string(approximation[i][0]);
		line += ",";
		line += to_string(approximation[i][1]);
		line += "\n";
		cout << line << endl;


		IO().writeFile(line, path);
		
		
	}

	return 0;
}
