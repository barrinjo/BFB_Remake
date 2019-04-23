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

void startGame() {
        std::cout << "WELCOME TO BLEAKFALLS BARROW!" << std::endl;
        loadLevel("startRoom.txt");
}

bool gameLoop() {
        bool exitFlag = false;
        while(!exitFlag) {
                splitInput(getInput());
        }
        return 0;
}

void loadLevel(std::string fileName) {
        std::string line;
        std::ifstream file(fileName);
        for(int i = 0; i < loadedFile.size(); i++) {
                loadedFile.pop_back();
        }
        loadedFile.clear();
        if(file.is_open()) {
                while(getline(file, line)) {
                        // std::cout << line << std::endl;
                        loadedFile.push_back(line);
                }
        }
        initMap();
        initDictionary();
        gameLoop();
}

#endif