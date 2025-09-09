#include "conway_func.h"
void drawLivingCells(std::vector<cell>* ptrToLivingCells, int xOffset, int yOffset, int cellDimension) {
    for(auto cell : *ptrToLivingCells) {
        DrawRectangle(xOffset + cellDimension * cell.m_x, yOffset + cellDimension * cell.m_y, cellDimension, cellDimension, MAROON);
    }
}

void countNeighborCells(std::vector<cell>* ptrToLivingCells, cell curCell) { // counts number of living neighbors around a cell, sets its neighbor count accordingly
    //int livingNeighorsCount = 0;
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(int i = 0; i < 8; i++) { // iterates through the local coordinate list
        cell search_cell = curCell + directions[i]; // actual direction of cell

        for(auto iterate_cell : *ptrToLivingCells) { // iterates through all living cells
            std::cout << 'x' << iterate_cell.m_x << 'y' << iterate_cell.m_y << std::endl;
            if(search_cell == iterate_cell)
                iterate_cell.m_LivingNeighborscCount++;
                //livingNeighorsCount++;
        }
    }
    //return livingNeighorsCount;
}

void iterateNeighboringCells(std::vector<cell>* ptrToDeadCells, std::vector<cell>* ptrToLivingCells) {
    std::vector<cell> directions = // a vector of local coordinates surrounding the cell
    {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };
/*
if deadcell is not in living cell list, add to dead cell list

add all neighbors of living cells into a vector
find all overlaps somehow?
return vector of dead cells to add or just edit existing one
*/

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
