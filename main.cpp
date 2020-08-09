#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Euclidean.h"

Map* readMap(const char* fileName);
void printMap(Map* map);

int main() {
    // Read in Map from file
    Map* map = readMap("test/10x10-01.map");

    // solve map with euclidean

    // print map
    printMap(map);
}

Map* readMap(const char* fileName) {
    // Create filestream
    std::ifstream file;
    // Open filestream
    file.open(fileName);

    // Redirect filestream to stdin
    auto cout_buf = std::cin.rdbuf(file.rdbuf());

    // Create temp map grid
    Map* map = new Map();
    
    char c;
    int y = 0;
    while(!std::cin.get(c).eof()) {
        if(c == '\n') {
            map->addRow();
            ++y;
        } else {
            map->pushColumn(y, c);
        }
    }

    std::cin.rdbuf(cout_buf);
    return map;
}

void printMap(Map* map) {
    std::cout << map->toString() << std::endl;
}