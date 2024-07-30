#pragma once

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

	static void writeFile(string text, string path) {
		// Cria e abre um arquivo de texto
		ofstream file(path);

		// Escreve no arquivo
		file << text;

		// Fecha o arquivo
		file.close();
	}

	// Retorna a lista de linhas em um arquivo.
	static vector<string> readFile(string path) {
		ifstream file(path);

		string line;
		vector<string> lineList;

		// Adiciona as linhas na lista.
		while (getline(file, line)) {
			lineList.push_back(line);
		}

		return lineList;
	}

	struct Type {
		static const int STRING = 0;
		static const int INT = 1;
		static const int DOUBLE = 2;
	};

	template <typename t>
	static vector<vector<t>> parsecsv(vector<string> linelist) {
		int doublequotescount = 0;
		int quotescount = 0;
		int parenthesescount = 0;

		// A posição inicia no (0, 0) [x, y]
		Position currentposition;

		// y<x<valor>>
		vector<vector<t>> valuematrix;

		for (currentposition.y; currentposition.y < linelist.size(); currentposition.y++) {
			string line = linelist[currentposition.y];
			vector<double> linetemp;
			string valuetemp;

			for (unsigned int i = 0; i < line.length(); i++) {
				char c = line[i];
				
				switch (c) {
					case ',': {
						if ((doublequotescount | quotescount | parenthesescount) > 0) {
							valuetemp += c;
						}
						else {
							// adiciona valor à lista temporária da linha.
							linetemp.push_back(stringToDouble(valuetemp));
							valuetemp = ""; // reinicia o valor.					
						}

						break;
					}
					case ';': {
						linetemp.push_back(stringToDouble(valuetemp));
						break;
					}

					// avisa que um valor string está começando ou terminando.
					case '"': {
						if (doublequotescount > 0) {
							doublequotescount--;
						}
						else {
							doublequotescount++;
						}
						break;
					}
					
					// Qualquer outro caractere que não se encaixe nas condições acima.
					default: {
						valuetemp += c;
					}

				}
			}
			valuematrix.push_back(linetemp);
		}


		return valuematrix;

	}

	static double stringToDouble(string s) {
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

	class SerialConfig;
};

