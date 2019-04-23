#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <map>

std::map<std::string, bool> responseMap;

void initMap(void) {
        responseMap["fWest"] = 0;
        responseMap["fEast"] = 0;
}
#endif