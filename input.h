#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<fstream>
#include<string>

#include "global.h"
#include "mapTest.h"

using std::string;

string getInput();
string response(string verb, string noun);
string lineCheck(int i);
void responseAction(int i);

string response(string verb, string noun) {
        // specialCase(loc);
        bool verb_flag = false;
        bool flag = false;
        int i = 0;
        while(true) {
                std::string line = loadedFile[i];
                if(flag) {
                        // return loadedFile[i + lineCheck(i)];
                        return lineCheck(i);
                }
                if(line == verb) {
                    verb_flag = true;
                }
                if(verb_flag && line == noun) {
                        flag = true;
                }
                i++;
                if(i == loadedFile.size()-1) {
                        if(!verb_flag && !flag)
                                return "SORRY, I DO NOT UNDERSTAND";
                }
        }
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
                verb="noverb";
                noun=input;
        }
        std::cout << response(verb, noun) << std::endl;
}

string getInput() {
        std::cout << "TELL ME WHAT TO DO?" << std::endl;
        std::string line;
        getline(std::cin, line);
        return line;
}

string lineCheck(int i) {
        string line = loadedFile[i];
        if(line[0] != 'f') {
                int temp = i;
                responseAction(++i);
                string print = loadedFile[temp];
                return print.erase(0,1);
        }
        else {
                int flag = 0;
                while(true) {
                        if(loadedFile[i][0] == '\"') {
                                if(flag == responseMap[line])  {
                                        int temp = i;
                                        responseAction(++i);
                                        string print = loadedFile[temp];
                                        return print.erase(0,1);
                                }
                                else {
                                        flag++;
                                }
                        }
                        i++;
                }
                // return responseMap[loadedFile[i]] + 1;
        }
}

void responseAction(int i) {
        while(loadedFile[i][0] != '\"') {
                if(loadedFile[i][0] == 't' || loadedFile[i][0] == 'n') {
                        bool newValue;
                        if(loadedFile[i][0] == 't')
                                newValue = true;
                        else
                                newValue = false;
                        string value = loadedFile[i];
                        value[0] = 'f';
                        responseMap[value] = newValue;
                }
                else
                        std::cout << loadedFile[i] << std::endl;
                i++;
        }
}

// void specialCase(std::string input) {
//         if(input == "QUIT") {
//                 return 0;
//         }
// }

#endif