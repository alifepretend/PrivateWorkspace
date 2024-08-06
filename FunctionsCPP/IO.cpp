#include "IO.h"

string temp = "";

void IO::writeFile(string text, string path, bool append) {
    // Cria e abre um arquivo de texto
    // ios::app -> append
    text.pop_back();
    ofstream file;
    if (append) {
        file.open(path, ios::app | std::ios_base::out);
    }
    else {
        file.open(path);
    }
    
    
    // Escreve no arquivo
    file << text;

    // Fecha o arquivo
    file.close();

    cout << text << "	Written to file" << endl;
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

double IO::stringToDouble(string s) {
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

IO::Serial::Serial(const char* serial_port, long int baud_rate) {
    // tenta iniciar conex�o com porta serial.
    erroropening = serial.openDevice(serial_port, baud_rate);

    // se conseguir abrir o dispositivo:
    if (erroropening == 1) {
        printf("successful connection to %s\n", serial_port);
    }
    else {
        cout << "erro ao tentar estabelecer conex�o com dispositivo." << endl;
    }
}

int IO::Serial::receiveData(string* line) {
    if (serial.available() != 0) {
        char c;

        serial.readChar(&c, 4);
            
        switch (c) {
            case ';': {               
                temp += c;
                *line = temp;
                temp = "";

                return 1;
                break;
            }
            case '/n': {
                break;
            }
            case '/r': {
                break;
            }
            case '/0': {
                break;
            }
            default: {
                temp += c;
            }
        }
    }

    return 0;
}
