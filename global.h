#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>
#include <thread>

void loadLevel();
std::string splitInput(std::string input);
std::string cardinalResponse(char target);

bool hard_flag;
bool exitFlag = false;
bool newLevel = true;
std::vector<std::string> loadedFile;
std::vector< std::vector<std::string> > dictionary;
std::string verb, noun;
std::string rString = "";
std::string lastInput = "";
std::string levelName = "startRoom.txt";


void sleepMilli(int x) {
        std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

#endif