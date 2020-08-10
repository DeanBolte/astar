#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Euclidean.h"

Map* readMap(const char* fileName);
void printMap(Map* map);

int main() {
    // Read in Map from file
    Map* map = readMap("test/4x4-01.map");
    // Print map after reading in
    std::cout << "Map from file:" << std::endl;
    printMap(map);

    // solve map with euclidean
    pathfind(map);

    // print map
    std::cout << std::endl << "Map after pathfind():" << std::endl;
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