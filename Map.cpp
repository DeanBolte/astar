#include "Map.h"

Map::Map() {
    
}

Map::~Map() {

}

char Map::position(int x, int y) {
    return grid.at(y);
}

void Map::position(int x, int y, char value) {
    grid[y][x] = value;
}