#include "Euclidean.h"

#include <iostream>

bool pathfind(Map* map) {
    // First Node
    Coords* start = map->locateChar('S');
    // Final Node
    Coords* end = map->locateChar('E');

    // Recursive find end
    return path(map, start, end);
}

float distance(Coords* start, Coords* end) {
    return sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
}

bool path(Map* map, Coords* start, Coords* end) {
    // If current node is the final node
    if(*start == *end) {
        return true;
    }

    // identifier for past nodes
    map->setValue(start, '-');

    // Stack of Nodes
    std::vector<Coords*> stack;

    // Add adjacent nodes to stack
    addCoordsToStack(start->x, start->y - 1, map, &stack);
    addCoordsToStack(start->x - 1, start->y, map, &stack);
    addCoordsToStack(start->x, start->y + 1, map, &stack);
    addCoordsToStack(start->x + 1, start->y, map, &stack);
    
    // Recursively pathfind from next closest node
    while(!stack.empty()) {
        Coords* next = stack.back();
        if(path(map, next, end)) {
            map->setValue(start, 'X');
            return true;
        }
        stack.pop_back();
    }
    return false;
}

void addCoordsToStack(int x, int y, Map* map, std::vector<Coords*>* stack) {
    if(y >= 0 && x >= 0 && (y < map->getHeight()  && x < map->getLength())) {
        if(map->getValue(x, y) == '*' || map->getValue(x, y) == 'E') {
            stack->push_back(new Coords(x, y));
        }
    }
}