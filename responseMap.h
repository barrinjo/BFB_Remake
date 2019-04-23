#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <map>

std::map<std::string, bool> responseMap;

void initMap(void) {
        responseMap["fStone"] = 0;
        responseMap["fNorth"] = 0;
        responseMap["fLock"] = 0;
}
#endif