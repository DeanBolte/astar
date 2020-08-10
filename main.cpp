// Please review License Agreement at the bottom of main.cpp

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

// MIT License

// Copyright (c) 2020 Dean Bolte

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.