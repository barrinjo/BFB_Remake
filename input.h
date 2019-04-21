#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<fstream>
#include<string>

#include "global.h"

using std::string;

string response(string verb, string noun);

string response(string verb, string noun) {
        // specialCase(loc);
        std::ifstream rFile("response_1.txt");
        string line;
        if(rFile.is_open()) {
                bool verb_flag = false;
                bool flag = false;
                while(getline(rFile ,line)) {
                        if(flag) {
                                return line;
                        }
                        if(line == verb) {
                            verb_flag = true;    
                        }
                        if(verb_flag && line == noun) {
                                flag = true;
                        }
                }
        } else {
                return "file missing: response_1.txt";
        }
        return "SORRY, I DO NOT UNDERSTAND";
}

void splitInput(string input) {
        size_t n;
        n = input.find(" ");
        if (n!=string::npos)
        {
                verb = input.substr(0, n);
                noun = input.substr(n + 1);
        }
        std::cout << response(verb, noun) << std::endl;
}

// void specialCase(std::string input) {
//         if(input == "QUIT") {
//                 return 0;
//         }
// }

#endif