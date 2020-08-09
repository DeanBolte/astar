#pragma once

#include <vector>
#include <string>

struct Coords {
    int x;
    int y;

    Coords(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Map {
public:
    // Constructors
    Map();
    ~Map();

    // Return char at Map Position
    char getValue(int x, int y);

    // Locate the first occurence of a specific char in a Map
    // Returns a coord of -1, -1 if the char doesnt exist
    Coords* locateChar(char c);

    // Edit Map Position
    void setValue(int x, int y, char value);
    void pushColumn(int y, char value);
    void addRow();

    // Print
    std::string toString();

private:
    // grid holds the map values
    std::vector<std::vector<char>> grid;

};