#pragma once

#include "Map.h"

// Takes an unsolved Map
// Returns a map with a path from the Start to the Exit
void pathfind(Map* map);

// Calculates the distance from End Node
float distanceToEnd(Coords start, Coords end);