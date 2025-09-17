#include "conway_func.h"
void drawLivingCells(const std::vector<cell>* ptrToLivingCells, int xOffset, int yOffset, int cellDimension) {
    cell center = {0,0};
    for(auto cell : *ptrToLivingCells) {
        Color chose = cell == center ? MAROON : PURPLE;
        DrawRectangle(xOffset + cellDimension * cell.m_x, yOffset + cellDimension * cell.m_y, cellDimension, cellDimension, chose);
    }
} 

// next iteration
void doConway(std::vector<cell>* ptrToLivingCells) {
    std::vector<cell> nextGenVec {}; // a temp vector to hold the next generation

    iterateThroughLiving(ptrToLivingCells, &nextGenVec);
    iterateThroughDead(ptrToLivingCells, &nextGenVec); 
    
    ptrToLivingCells->swap(nextGenVec);
    resetCell(ptrToLivingCells);
}

// resets all living neighbors count in cell to 0
void resetCell(std::vector<cell>* ptrToLivingCells) {
    for(auto&& C : *ptrToLivingCells)
        C.m_LivingNeighborscCount = 0;
}

// sends all valid living cells to the next generation
void iterateThroughLiving(std::vector<cell>* ptrToLivingCells, std::vector<cell>* nextGenVec) {
    for(auto&& A : *ptrToLivingCells) {
        countNeighborCells(ptrToLivingCells, A);
        if(A.m_LivingNeighborscCount == 2 || A.m_LivingNeighborscCount == 3) {
            nextGenVec->push_back(A);
        }
    }
}

// this function iterates through all dead neighboring cells and checks if they should come to life
void iterateThroughDead(const std::vector<cell>* ptrToLivingCells, std::vector<cell>* nextGenVec) {
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},         {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(auto livingCell : *ptrToLivingCells) { 
        for(int i = 0; i < 8; i++) { // iterates through all neighboring cells
            cell deadCell = livingCell + directions[i]; // actual position of cell
            if(isCellInVector(nextGenVec, deadCell)) { // checks if cell has already been evaluated
                continue;
            }
            countNeighborCells(ptrToLivingCells, deadCell);
            if(deadCell.m_LivingNeighborscCount == 3) { // check if the cell should live
                nextGenVec->push_back(deadCell);
            }
        }
    }

}

// counts number of living neighbors around a cell, sets its internal neighbor count accordingly
void countNeighborCells(const std::vector<cell>* ptrToLivingCells, cell& curCell) { 
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},         {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(int i = 0; i < 8; i++) { // iterates through the local coordinate list
        cell queryCell = curCell + directions[i]; // world pos of cell local to living cell being radar'd
        if(isCellInVector(ptrToLivingCells, queryCell))
            curCell.m_LivingNeighborscCount++;
    }
}

// self-explanatory
bool isCellInVector(const std::vector<cell>* searchVector, const cell queryCell) {
    for(auto searchCell : *searchVector) {
        if(queryCell == searchCell)
            return true;
    }
    return false;
}

// operator overloads
cell operator+(cell& a, cell& b) { return cell { a.m_x + b.m_x, a.m_y + b.m_y }; }
cell operator-(cell& a, cell& b) { return cell {a.m_x - b.m_x, a.m_y - b.m_y}; }
bool operator==(cell& a, cell& b) {
    if(a.m_x == b.m_x && a.m_y == b.m_y)
        return true;
    else
        return false;
}

bool operator==(const cell& a, const cell& b) {
    if(a.m_x == b.m_x && a.m_y == b.m_y)
        return true;
    else
        return false;
}
