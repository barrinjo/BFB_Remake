#ifndef LOOP_H
#define LOOP_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "global.h"
#include "input.h"

bool gameLoop();
string getInput();
void loadLevel(std::string fileName);

void startGame() {
        loadLevel("response_1.txt");
        std::cout << "WELCOME TO BLEAKFALLS BARROW!" << std::endl;
        gameLoop();
}

bool gameLoop() {
        bool exitFlag = false;
        while(!exitFlag) {
                splitInput(getInput());
        }
        return 0;
}

string getInput() {
        std::cout << "TELL ME WHAT TO DO?" << std::endl;
        std::string line;
        getline(std::cin, line);
        return line;
}

void loadLevel(std::string fileName) {
        std::string line;
        std::ifstream file(fileName);
        if(file.is_open()) {
                while(getline(file, line)) {
                        loadedFile.push_back(line);
                }
        }
}

#endif