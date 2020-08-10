#include "Euclidean.h"

bool pathfind(Map* map) {
    // First Node
    Coords* start = map->locateChar('S');
    // Final Node
    Coords* end = map->locateChar('E');

    // Stack of Nodes
    std::vector<Coords*> stack;

    // Recursive find end
    return path(map, start, end, stack);
}

float distance(Coords* start, Coords* end) {
    return sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
}

bool path(Map* map, Coords* start, Coords* end, std::vector<Coords*> stack) {
    if(*start == *end) {

    }

}