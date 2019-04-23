#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "global.h"

std::string lookup(std::string line);

void initDictionary() {
        std::cout << "what" << std::endl;
        std::ifstream file("dictionary.txt");
        std::string line;
        if(file.is_open()) {
                std::vector<std::string> temp;
                while(getline(file, line)) {
                        if(line != "xxx") {
                                temp.push_back(line);
                        } else {
                                dictionary.push_back(temp);
                            temp.clear();
                        }
                }
                std::cout << "dicitonary initialized" << std::endl;
        } else {
                std::cout << "dictionary.txt missing" << std::endl;
        }
}

std::string lookup(std::string line) {
        for(int i = 0; i < dictionary.size(); i++) {
                for(int j = 0; j < dictionary[i].size(); j++) {
                        if(line == dictionary[i][j])
                                return dictionary[i][0];
                }
        }
        return line;
}

#endif