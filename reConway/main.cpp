#include "conway_func.h"

void prinVec(std::vector<cell>* vec) {
    for(auto v : *vec) {
        std::cout << '(' << v.m_x << ',' << v.m_y << ')' << '\t';
    }
    std::cout << std::endl;
}


int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    const int cellDimension = 15; // dimension of the living cells

    const int xOffset = 500; // horizontal offset of the living cells
    const int yOffset = 500; // vertical offset of the living cells
    
    // living cells
    //std::vector<cell> livingCells = {{0, 0}, {1,-1}, {2,-1}, {2,0}, {2,1}}; 
    std::vector<cell> livingCells = {{0, 0}, {0,2}, {1,2}, {1,1}, {1,2}, {-1,2}};
    
    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");
    SetTargetFPS(60);

    countNeighborCells(&livingCells, livingCells[0]);
    //std::cout << livingCells[0].m_LivingNeighborscCount << std::endl;
    int counter = 0;
    prinVec(&livingCells);

    while(!WindowShouldClose()) {
        counter++;

        if(counter > 50) {
            std::cout << "bing" << std::endl;
            doConway(&livingCells);
            counter = 0;
            prinVec(&livingCells);
        }

        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            drawLivingCells(&livingCells, xOffset, yOffset, cellDimension);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}

//g++ main.cpp conway_func.cpp -o conway -IC:\libraries\raylib\raylib\src -LC:\libraries\raylib\raylib\src -lraylib -lopengl32 -lwinmm -lgdi32
