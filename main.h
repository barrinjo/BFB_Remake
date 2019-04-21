#ifndef MAIN_H
#define MAIN_H

#include<fstream>
#include<string>

using std::string;

string response(string loc);

string response(string loc) {
        std::ifstream rFile("response_1.txt");
        string line;
        if(rFile.is_open()) {
                bool flag = false;
                while(getline(rFile ,line)) {
                        if(flag == true) {
                                return line;
                        }
                        if(line == loc) {
                            flag = true;    
                        }
                }
        } else {
                return "file missing: response_1.txt";
        }
        return "xxx";
}

#endif