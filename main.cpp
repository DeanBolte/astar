// Please review License Agreement at the bottom of main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Map.h"
#include "Euclidean.h"
#include "MapGenerator.h"

Map* readMap(const char* fileName);
void printMap(Map* map);
void printMapToFile(Map* map, const char* fileName);

int main(int argc, char** argv) {
    if(argc > 1) {
        Map* map = nullptr;
        if(std::string(argv[1]) == "-filein") {
            // Read in Map from file
            map = readMap(argv[2]);
        } else if(std::string(argv[1]) == "-random") {
            map = generateMapRandomly(std::atoi(argv[2]));
        } else {
            std::cout << "No valid input, example size 16 Map:" << std::endl;
            map = generateMapRandomly(16);
        }

        // solve map with euclidean
        auto start = std::chrono::steady_clock::now();
        pathfind(map);
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        printMap(map);

        std::cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count() << " ns" << std::endl;

        printMapToFile(map, "output.txt");
    } else {
        std::cout << "!No input!" << std::endl;
        Map* map = generateMapRandomly(48, 20);
        pathfind(map);
        printMap(map);
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