#ifndef LOOP_H
#define LOOP_H

#include <string>
#include <iostream>

#include "main.h"

bool gameLoop();
string getInput();

void startGame() {
        std::cout << "WELCOME TO BLEAKFALLS BARROW!" << std::endl;
        gameLoop();
}

bool gameLoop() {
        bool exitFlag = false;
        while(!exitFlag) {
                std::cout << response(getInput()) << std::endl;
        }
        return 0;
}

string getInput() {
        std::cout << "TELL ME WHAT TO DO?" << std::endl;
        std::string line;
        getline(std::cin, line);
        return line;
}

#endif