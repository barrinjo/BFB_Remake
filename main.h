#ifndef MAIN_H
#define MAIN_H

#include<fstream>
#include<string>

using std::string;

string response(int loc);

string response(int loc) {
        std::ifstream rFile("response_1.txt");
        if(rFile.is_open()) {
                return "file is open";
        } else {
                return "u dumb";
        }
}

#endif