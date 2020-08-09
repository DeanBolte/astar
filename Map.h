#pragma once

#include <vector>
#include <string>

class Map {
public:
    // Constructors
    Map();
    ~Map();

    // Return char at Map Position
    char getValue(int x, int y);

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