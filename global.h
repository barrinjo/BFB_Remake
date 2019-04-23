#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>

void loadLevel(std::string fileName);
void splitInput(std::string input);

std::string verb, noun;
bool hard_flag;
std::vector<std::string> loadedFile;

#endif