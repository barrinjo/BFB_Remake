#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <map>
#include "global.h"

std::map<std::string, bool> responseMap;

void initMap(void) {
        int i = 0;
        std::string line = loadedFile[i];
        while(line[0] == 'f') {
                responseMap[line] = 0;
                line = loadedFile[++i];
        }
        std::cout << line << std::endl;
}
#endif