#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<fstream>
#include<string>

#include "global.h"
#include "responseMap.h"
#include "loop.h"
#include "dictionary.h"

using std::string;

string getInput();
string response(string verb, string noun);
string lineCheck(int i);
void responseAction(int i);
std::string helpString = "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";


string response(string verb, string noun) {
        // specialCase(loc);
        bool verb_flag = false;
        bool flag = false;
        unsigned int i = 0;
        if(verb == "QUIT") {
                exitFlag = true;
                return "THANKS FOR PLAYING!";
        }
        if(verb == "HELP") {
                return helpString;
        }
        while(true) {
                std::string line = loadedFile[i];
                if(flag) {
                        // return loadedFile[i + lineCheck(i)];
                        return lineCheck(i);
                }
                if(line == verb) {
                        // if(noun == "input") {
                        //         flag = true;
                        // }
                        verb_flag = true;
                }
                if(line == "STOP")
                        verb_flag = false;
                if(verb_flag && line == noun)
                        flag = true;
                i++;
                if(i == loadedFile.size()-1) {
                        return "I CAN'T DO THAT.";
                }
        }
}

string splitInput(string input) {
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
        return response(lookup(verb), lookup(noun));
}

string getInput() {
        std::string line;
        getline(std::cin, line);
        lastInput = line;
        return splitInput(line);
}

string lineCheck(int i) {
        string line = loadedFile[i];
        std::cout << line << std::endl;
        if(line[0] != 'f') {
                if(line[0] == '_') {
                        levelName = loadedFile[i].erase(0,1);
                        newLevel = true;
                } else {
                        int temp = i;
                        responseAction(++i);
                        string print = loadedFile[temp];
                        return print.erase(0,1);
                }
        } else {
                int flag = 0;
                int goal = 0 + responseMap[line];
                int goalCount = 2;
                i++;
                while(true) {
                        if(loadedFile[i][0] == '\"') {
                                if(flag == goal)  {
                                        int temp = i;
                                        responseAction(++i);
                                        string print = loadedFile[temp];
                                        return print.erase(0,1);
                                }
                                else {
                                        flag++;
                                }
                        } else if (loadedFile[i][0] == 'f') {
                                goal += goalCount * responseMap[loadedFile[i]];
                                goalCount *= 2;
                        }
                        i++;
                }
                // return responseMap[loadedFile[i]] + 1;
        }
        return "XXX";
}

string cardinalResponse(char target) {
        int i = 0;
        int flag = 0;
        int goal = 0;
        int goalCount = 1;
        while(true) {
                if(loadedFile[i][0] == target) {
                        while(true) {
                                if(loadedFile[i][0] == 'f') {
                                        goal += goalCount * responseMap[loadedFile[i]];
                                        goalCount *= 2;
                                }
                                if(loadedFile[i][0] == '\"') {
                                        if(flag == goal) {
                                                string print = loadedFile[i];
                                                return print.erase(0,1);
                                        }
                                        else {
                                                flag++;
                                        }
                                }
                                i++;
                        }
                }
                i++;
        }
}

void responseAction(int i) {
        while(loadedFile[i][0] != '\"') {
                if(loadedFile[i][0] == '_') {
                        levelName = loadedFile[i].erase(0,1);
                        newLevel = true;
                }
                if(loadedFile[i][0] == 't' || loadedFile[i][0] == 'n') {
                        bool newValue;
                        if(loadedFile[i][0] == 't')
                                newValue = true;
                        else
                                newValue = false;
                        string value = loadedFile[i];
                        value[0] = 'f';
                        responseMap[value] = newValue;
                } else {
                        // std::cout << loadedFile[i] << std::endl;
                }
                i++;
        }
}

// void specialCase(std::string input) {
//         if(input == "QUIT") {
//                 return 0;
//         }
// }

#endif