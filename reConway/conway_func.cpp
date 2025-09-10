#include "conway_func.h"
void drawLivingCells(std::vector<cell>* ptrToLivingCells, int xOffset, int yOffset, int cellDimension) {
    cell center = {0,0};
    for(auto cell : *ptrToLivingCells) {
        Color chose = cell == center ? MAROON : PURPLE;
        DrawRectangle(xOffset + cellDimension * cell.m_x, yOffset + cellDimension * cell.m_y, cellDimension, cellDimension, chose);
    }
}

/*
order of execution

iteratethroughdead
iteratethoughliving

*/

void doConway(std::vector<cell>* ptrToLivingCells) {
    std::vector<cell> tempStorageVector {};

    iterateThroughLiving(ptrToLivingCells, &tempStorageVector); // delete dead cells from living vector
    iterateThroughDead(ptrToLivingCells, &tempStorageVector); // add dead cells to living vector

    (*ptrToLivingCells) = tempStorageVector;
}

void iterateThroughLiving(std::vector<cell>* ptrToLivingCells, std::vector<cell>* tempStorageVector) {
    // purpose of this function is decide which of the current cells live
    /*
    for(auto queryCell : *ptrToLivingCells){
        countNeighborCells(ptrToLivingCells, queryCell);
        if(queryCell.m_LivingNeighborscCount == 2 || queryCell.m_LivingNeighborscCount == 3) {
            tempStorageVector->push_back(queryCell);
        }
    }*/
    auto i = ptrToLivingCells->begin();
    while(i != std::end(*ptrToLivingCells)) {

    }
    /*
    for(int i = 0; i < ptrToLivingCells->size(); i++) {
        cell queryCell = (*ptrToLivingCells)[i];
        if(queryCell.m_LivingNeighborscCount == 2 || queryCell.m_LivingNeighborscCount == 3) {
            continue
        }else{

        }
    }*/
}

void iterateThroughDead(std::vector<cell>* ptrToLivingCells, std::vector<cell>* tempStorageVector) {
    // purpose of this function is to add all neighboring cells to the living cell vector
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(auto livingCell : *ptrToLivingCells) {
        for(int i = 0; i < 8; i++) {
            cell queryCell = livingCell + directions[i];
            if(isCellLiving(ptrToLivingCells, queryCell)) {
                continue;
            }else{
                countNeighborCells(ptrToLivingCells, queryCell);
                if(queryCell.m_LivingNeighborscCount == 3) {
                    tempStorageVector->push_back(queryCell);
                    //add queryCell to vector
                }
            }
        }
        
    }

}

void countNeighborCells(std::vector<cell>* ptrToLivingCells, cell& curCell) { // counts number of living neighbors around a cell, sets its neighbor count accordingly
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(int i = 0; i < 8; i++) { // iterates through the local coordinate list
        cell queryCell = curCell + directions[i]; // world pos of cell local to living cell being radar'd

        if(isCellInVector(ptrToLivingCells, queryCell))
            curCell.m_LivingNeighborscCount++;
    }
}

bool isCellInVector(std::vector<cell>* searchVector, cell queryCell) {
    for(auto searchCell : *searchVector) {
        if(queryCell == searchCell)
            return true;
    }
    return false;
}

bool isCellLiving(std::vector<cell>* ptrToLivingCells, cell queryCell) { // if the (query)cell we are looking at is currently living, return true
    for(cell living : *ptrToLivingCells) {
        if(queryCell == living) 
            return true;
    }
    return false;
}

cell operator+(cell& a, cell& b) { return cell { a.m_x + b.m_x, a.m_y + b.m_y }; }
cell operator-(cell& a, cell& b) { return cell {a.m_x - b.m_x, a.m_y - b.m_y}; }
bool operator==(cell& a, cell& b) {
    if(a.m_x == b.m_x && a.m_y == b.m_y)
        return true;
    else
        return false;
}


/*
game of life rules

1. live cells w/ <2 neighbors die(under pop)
2. live cells w/ 2||3 neighbors live to next gen
3. live cells w/ >3 neighbors dies(overpop)
4. dead cells w/ ==3 neighbors becomes living(reproduction)
*/
