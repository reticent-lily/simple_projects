#ifndef CONWAY_FUNCTIONS
#define CONWAY_FUNCTIONS

#include "iostream"
#include "raylib.h"
#include "vector"

struct cell {
    int m_x;
    int m_y;
    int m_LivingNeighborscCount{0};
};

cell operator+(cell& a, cell& b);
cell operator-(cell& a, cell& b);
bool operator==(cell& a, cell& b);

void drawLivingCells(std::vector<cell>* ptrToLivingCells, int xOffset, int yOffset, int cellDimension) ; // iterates through vector and draws cells accordingly
void countNeighborCells(std::vector<cell>* ptrToLivingCells, cell& curCell); // counts and sets the number of living cells surrounding 'curCell' in the vector
bool isCellInVector(std::vector<cell>* searchVector, cell queryCell);

bool isCellLiving(std::vector<cell>* ptrToLivingCells, cell queryCell);
void iterateThroughLiving(std::vector<cell>* ptrToLivingCells, std::vector<cell>* tempStorageVector);
void iterateThroughDead(std::vector<cell>* ptrToLivingCells, std::vector<cell>* tempStorageVector);
void doConway(std::vector<cell>* ptrToLivingCells);

#endif
