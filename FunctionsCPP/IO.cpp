#include "io.h"


void IO::writeFile(string text, string path) {
    // Cria e abre um arquivo de texto
    // ios::app -> append
    ofstream file(path, ios::app);

    // Escreve no arquivo
    file << text;

    // Fecha o arquivo
    file.close();
}

vector<string> IO::readFile(string path) {
    ifstream file(path);

    string line;
    vector<string> lineList;

    // Adiciona as linhas na lista.
    while (getline(file, line)) {
        lineList.push_back(line);
    }

    return lineList;
}

vector<vector<double>> IO::parsecsv(vector<string> linelist) {
    int doublequotescount = 0;
    int quotescount = 0;
    int parenthesescount = 0;

    // A posição inicia no (0, 0) [x, y]
    Position currentposition;

    // y<x<valor>>
    vector<vector<double>> valuematrix;

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



//class SerialManager {
//private:
//	
//public:
//	serialib serial;
//	// Inicia a porta serial.
//	SerialManager(char* serial_port, long int baud_rate) {
//
//		// Tenta iniciar conex�o com porta serial.
//		char errorOpening = serial.openDevice(serial_port, baud_rate);
//
//		// Se conseguir abrir o dispositivo:
//		if (errorOpening == 1) {
//			printf("Successful connection to %s\n", serial_port);
//		}
//		else {
//			cout << "Erro ao tentar estabelecer conex�o com dispositivo." << endl;
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

