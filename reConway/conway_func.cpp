#ifndef CONWAY_FUNCTIONS
#define CONWAY_FUNCTIONS

#include "iostream"
#include "raylib.h"
#include "vector"

struct cell {
    int m_x;
    int m_y;
};

cell operator+(cell& a, cell& b);
cell operator-(cell& a, cell& b);
bool operator==(cell& a, cell& b);

void drawLivingCells(std::vector<cell>* ptrToLivingCells, int xOffset, int yOffset, int cellDimension) ; // iterates through vector and draws cells accordingly
int countNeighborCells(std::vector<cell>* ptrToLivingCells, cell curCell); // counts and returns the number of living cells surrounding 'curCell' in the vector

#endif
