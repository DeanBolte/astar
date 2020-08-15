#pragma once

#include "Map.h"
#include <ctime>
#include <cstdlib>

// Return Map generated randomly of size input
Map* generateMapRandomly(int length);
Map* generateMapRandomly(int length, int height);