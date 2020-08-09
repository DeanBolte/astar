#include "Euclidean.h"
#include <math.h>

void pathfind(Map* map) {
    
}

float distanceToEnd(Coords* start, Coords* end) {
    return sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
}