#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <map>
#include "global.h"

std::map<std::string, bool> responseMap;

int initMap(std::string fileName) {
        if(responseMap[fileName])
                return 1;
        int i = 0;
        std::string line = loadedFile[i];
        while(line[0] == 'f') {
                responseMap[line] = 0;
                line = loadedFile[++i];
        }
        responseMap[fileName] = 1;
        std::cout << line << std::endl;
        return 0;
}

#endif