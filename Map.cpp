#include "Map.h"

Map::Map() {
    addRow();
}

Map::~Map() {

}

char Map::getValue(int x, int y) {
    return grid.at(y).at(x);
}

void Map::setValue(int x, int y, char value) {
    grid.at(y).at(x) = value;
}

void Map::pushColumn(int y, char value) {
    grid.at(y).push_back(value);
}

void Map::addRow() {
    std::vector<char> row;
    grid.push_back(row);
}

Coords* Map::locateChar(char c) {
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid.at(i).size(); ++j) {
            if(grid.at(i).at(j) == c) {
                return new Coords(j, i);
            }
        }
    }
    return new Coords(-1, -1);
}

std::string Map::toString() {
    std::string out = "";

    for(unsigned int i = 0; i < grid.size(); ++i) {
        for(unsigned int j = 0; j < grid.at(i).size(); ++j) {
            out += grid.at(i).at(j);
        }
        out += '\n';
    }

    return out;
}