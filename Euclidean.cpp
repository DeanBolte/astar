#include "Euclidean.h"

#include <iostream>

static Map* map;

static void addCoordsToStack(int x, int y, std::vector<Coords*>& stack) {
    if(y >= 0 && x >= 0 && (y < map->getHeight()  && x < map->getLength())) {
        if(map->getValue(x, y) == MAPEMPTY || map->getValue(x, y) == MAPEND) {
            stack.push_back(new Coords(x, y));
        }
    }
}

static void sort(std::vector<Coords*>& stack, Coords* endCoords, int start, int end) {
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

static bool path(Coords* start, Coords* end) {
    // If current node is the final node
    if(*start == *end) {
        return true;
    }

    // identifier for past nodes
    map->setValue(start, MAPEXPLORED);

    // Stack of Nodes
    std::vector<Coords*> stack;

    // Add adjacent nodes to stack
    addCoordsToStack(start->x, start->y - 1, stack);
    addCoordsToStack(start->x - 1, start->y, stack);
    addCoordsToStack(start->x, start->y + 1, stack);
    addCoordsToStack(start->x + 1, start->y, stack);

    // Sort stack
    sort(stack, end, 0, stack.size() - 1);
    
    // Recursively pathfind from next closest node
    while(!stack.empty()) {
        Coords* next = stack.back();
        if(path(next, end)) {
            map->setValue(start, MAPPATH);
            return true;
        }
        stack.pop_back();
    }
    return false;
}

bool pathfind(Map* mapptr) {
    map = mapptr;
    // First Node
    Coords* start = map->locateChar('S');
    // Final Node
    Coords* end = map->locateChar('E');

    // Recursive find end
    return path(start, end);
}

float distance(Coords* start, Coords* end) {
    return sqrt(pow(end->x - start->x, 2) + pow(end->y - start->y, 2));
}