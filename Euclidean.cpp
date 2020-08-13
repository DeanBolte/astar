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

    // Sort stack
    sort(stack, end, 0, stack.size() - 1);
    
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

void sort(std::vector<Coords*>& stack, Coords* endCoords, int start, int end) {
    if(start >= end) {
        return;
    }

    float pivot = distance(stack.at(end), endCoords);

    int pivotIndex = start;

    for(int i = start; i < end; ++i) {
        if(distance(stack.at(i), endCoords) >= pivot) {
            // swap coords at i with coords at pivot index
            Coords* temp = stack.at(i);
            stack.at(i) = stack.at(pivotIndex);
            stack.at(pivotIndex) = temp;
            ++pivotIndex;
        }
    }
    // swap coords at end with coords at pivot index
    Coords* temp = stack.at(end);
    stack.at(end) = stack.at(pivotIndex);
    stack.at(pivotIndex) = temp;
    
    sort(stack, endCoords, start, pivotIndex - 1);
    sort(stack, endCoords, pivotIndex + 1, end);    
}