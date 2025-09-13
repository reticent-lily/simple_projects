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
    std::vector<cell> neighbor {};
    
    iterateThroughDead(ptrToLivingCells, &neighbor); 
    iterateThroughLiving(ptrToLivingCells); 

    for(int i = 0; i < neighbor.size(); i++) {
        ptrToLivingCells->push_back(neighbor[i]);
    }
}

// this function iterates through all dead neighboring cells and checks if they should come to life
void iterateThroughDead(std::vector<cell>* ptrToLivingCells, std::vector<cell>* neighborStorageVec) {
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(auto livingCell : *ptrToLivingCells) { 
        for(int i = 0; i < 8; i++) { // iterates through all neighboring cells
            cell queryCell = livingCell + directions[i]; // actual position of cell
            if(isCellLiving(ptrToLivingCells, queryCell)) { // checks if neighboring cell is living
                continue;
            }else{
                countNeighborCells(ptrToLivingCells, queryCell);
                if(queryCell.m_LivingNeighborscCount == 3) { // check if the cell should live
                    neighborStorageVec->push_back(queryCell);
                    //add queryCell to vector
                }
            }
        }
        
    }

}

void iterateThroughLiving(std::vector<cell>* ptrToLivingCells) {
    for(int i; i < ptrToLivingCells->size(); i++) { // iterates through all living cells
        cell A = (*ptrToLivingCells)[i];
        countNeighborCells(ptrToLivingCells, A);
        if(A.m_LivingNeighborscCount == 2 || A.m_LivingNeighborscCount == 3) {
            continue;
        }else{
            ptrToLivingCells->erase(ptrToLivingCells->begin() + i); // erases cell from living vector
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
