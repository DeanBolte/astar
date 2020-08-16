#include "MapGenerator.h"

#define EMPTYRATIO 5

// Return a randomly generated Map of size length by height
Map* generateMapRandomly(int length, int height) {
    // Seed random function
    std::srand(std::time(0));

    // Create Map on heap to return
    Map* map = new Map();

    // Generate each map character and push to map grid
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < length; ++j) {
            map->pushColumn(i, std::rand() % EMPTYRATIO > 0 ? MAPEMPTY : MAPWALL);
        }
        map->addRow();
    }

    // Create entry point
    Coords* start = new Coords(std::rand() % (length - 1), std::rand() % (height - 1));
    map->setValue(start, MAPSTART);
    // create exit point
    Coords* end = new Coords(std::rand() % (length - 1), std::rand() % (height - 1));
    map->setValue(end, MAPEND);

    return map;
}

// Generate map using lenght of same value as height
Map* generateMapRandomly(int length) {
    return generateMapRandomly(length, length);
}