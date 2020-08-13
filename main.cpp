// Please review License Agreement at the bottom of main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Map.h"
#include "Euclidean.h"

Map* readMap(const char* fileName);
void printMap(Map* map);
void printMapToFile(Map* map, const char* fileName);

int main(int argc, char** argv) {
    // Command Line: astar <map file name> <pre/post map print>(y/n) <print to file>(file name)
    if(argc > 2) {
        // Read in Map from file
        Map* map = readMap(argv[1]);
        
        // If commandline pre/post map print == yes
        if(*argv[2] == 'y') {
            std::cout << "Map from file:" << std::endl;
            printMap(map);
        }

        // solve map with euclidean
        auto start = std::chrono::steady_clock::now();
        pathfind(map);
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        if(*argv[2] == 'y') {
            std::cout << "Map after pathfind():" << std::endl;
            printMap(map);
        }
        
        std::cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() << " ns" << std::endl;

        // Print to file
        if(argc > 3) {
            printMapToFile(map, argv[3]);
        }
    } else {
        std::cout << "not enough arguments" << std::endl;
    }
}

Map* readMap(const char* fileName) {
    // Create filestream
    std::ifstream file;
    file.open(fileName);

    // Redirect filestream to stdin
    auto cin_buf = std::cin.rdbuf(file.rdbuf());

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
    
    std::cin.rdbuf(cin_buf);
    file.close();
    return map;
}

void printMap(Map* map) {
    std::cout << map->toString() << std::endl;
}

void printMapToFile(Map* map, const char* fileName) {
    // create file stream
    std::ofstream file;
    file.open(fileName);

    // Push map.toString() to file
    file << map->toString();

    file.close();
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