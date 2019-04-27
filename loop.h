#ifndef LOOP_H
#define LOOP_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "global.h"
#include "input.h"
#include "responseMap.h"
#include "dictionary.h"

bool gameLoop();
std::string getInput();
void loadCardinal();
void typewriter(std::string);

void startGame() {
        std::cout << "WELCOME TO BLEAKFALLS BARROW!" << std::endl;
        loadLevel();
}

bool gameLoop() {
        while(!exitFlag) {
                if(newLevel == true) {
                        loadLevel();
                }
                std::cout << "\033[2J\033[1;1H" << std::flush;
                loadCardinal();
                // if(!turnCount++) {
                //         std::cout << "TELL ME WHAT TO DO? " << std::flush;
                // }
                if(lastInput != "") {
                        std::cout << "TELL ME WHAT TO DO? " << lastInput << std::endl;
                        typewriter(rString);
                        std::cout << std::endl << "TELL ME WHAT TO DO? " << std::flush;
                        rString = getInput();
                } else {
                        std::cout << "TELL ME WHAT TO DO? " << std::flush;
                        rString = getInput();
                }
        }
        return 0;
}

void typewriter(std::string x) {
        std::cout << "OK," << std::endl;
        sleepMilli(500);
        for(unsigned int i = 0; i < x.size(); i++) {
                std::cout << x[i] << std::flush;
                if(x[i] == '.') {
                        sleepMilli(300);
                }
                if(x[i] == ',') {
                        sleepMilli(150);
                }
                sleepMilli(20);
        }
}

void loadCardinal() {
        using std::cout;
        using std::endl;

        cout << cardinalResponse('N') << endl;
        cout << cardinalResponse('S') << endl;
        cout << cardinalResponse('E') << endl;
        cout << cardinalResponse('W') << endl;
}

void loadLevel() {
        std::string line;
        std::ifstream file("levels/" + levelName);
        loadedFile.clear();
        if(file.is_open()) {
                while(getline(file, line)) {
                        // std::cout << line << std::endl;
                        loadedFile.push_back(line);
                }
        } else {
                std::cout << levelName << " missing." << std::endl;
                exitFlag = true;
        }
        file.close();
        initMap(levelName);
        initDictionary();
        newLevel = false;
        gameLoop();
}

#endif