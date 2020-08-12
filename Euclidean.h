#pragma once

#include "Map.h"
#include <math.h>
#include <vector>

// Takes an unsolved Map
// Returns a map with a path from the Start to the Exit
bool pathfind(Map* map);

// Calculates the distance from End Node
float distance(Coords* start, Coords* end);

// Recursive function for finding path to end
bool path(Map* map, Coords* start, Coords* end);

// Adds the Coords to the stack
void addCoordsToStack(int x, int y, Map* map, std::vector<Coords*>* stack);

// Sort stack by distance to the end
void sort(std::vector<Coords*>* stack, Coords* endCoords, int start, int end);