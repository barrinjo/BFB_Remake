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
        bool verb_flag = false;
        bool flag = false;
        int i = 0;
        while(true) {
                std::string line = loadedFile[i++];
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
        return "SORRY, I DO NOT UNDERSTAND";
}

void splitInput(string input) {
        string spaceHold = input;
        size_t found = spaceHold.find(" ");
        if (found!=string::npos) {
                size_t n;
                n = input.find(" ");
                if (n!=string::npos)
                {
                        verb = input.substr(0, n);
                        noun = input.substr(n + 1);
                }
        }
        else {
                verb=input;
                noun=input;
        }
        std::cout << response(verb, noun) << std::endl;
}

// void specialCase(std::string input) {
//         if(input == "QUIT") {
//                 return 0;
//         }
// }

#endif