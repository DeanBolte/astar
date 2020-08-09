#pragma once

#include <vector>

class Map {
public:
    // Constructors
    Map();
    ~Map();

    // Return char at Map Position
    char position(int x, int y);

    // Edit Map Position
    void position(int x, int y, char value);

private:
    // grid holds the map values
    std::vector<std::vector<char>> grid;

};