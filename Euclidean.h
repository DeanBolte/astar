#pragma once

#include "Map.h"
#include <math.h>
#include <vector>

// Takes an unsolved Map
// Returns a map with a path from the Start to the Exit
bool pathfind(Map* map);

// Calculates the distance from End Node
float distance(Coords start, Coords end);

// Recursive function for finding path to end
bool path(Map* map, Coords* start, Coords* end, std::vector<Coords*> stack);