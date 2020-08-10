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

    bool operator==(const Coords& coords) {
        return (x == coords.x && y == coords.y);
    }
};

class Map {
public:
    // Constructors
    Map();
    ~Map();

    // Return char at Map Position
    char getValue(Coords* coords);

    // Locate the first occurence of a specific char in a Map
    // Returns a coord of -1, -1 if the char doesnt exist
    Coords* locateChar(char c);

    // Edit Map Position
    void setValue(Coords* coords, char value);
    
    // Push to the end of a row
    void pushColumn(int y, char value);

    // Add a row to the Map
    void addRow();

    // Build a formatted string of the Map
    std::string toString();

private:
    // grid holds the map values
    std::vector<std::vector<char>> grid;

};