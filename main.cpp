#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Euclidean.h"

Map* readMap(const char* fileName);

int main() {
    // Read in Map from file
    Map* map = readMap("test.txt");

    // solve map with euclidean

    // print map
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
    

    return map;
}