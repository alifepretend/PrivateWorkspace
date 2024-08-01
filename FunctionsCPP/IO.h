#pragma once

#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <codecvt>
#include <locale>
#include "serialib/serialib.h"

using namespace std;

class IO
{
public:
	struct Position{
		unsigned int x = 0;
		unsigned int y = 0;
	};

	void writeFile(string text, string path);

	// Retorna a lista de linhas em um arquivo.
	static vector<string> readFile(string path);

	struct Type {
		static const int STRING = 0;
		static const int INT = 1;
		static const int DOUBLE = 2;
	};

	vector<vector<double>> parsecsv(vector<string> linelist);


};

double stringToDouble(string s) {
	istringstream iss(s);
	double value;
	// Tenta extrair um double do stream
	if (iss >> value) {
		return value;
	}
	else {
		return 0;
	}
}

//class SerialManager {
//public:
//	SerialManager(char* serial_port, long int baud_rate);
//
//	int receiveData(string * line);
//};

#endif // !IO_H
