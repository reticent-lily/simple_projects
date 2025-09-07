#include "conway_func.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    const int cellDimension = 15; // dimension of the living cells

    const int xOffset = 500; // horizontal offset of the living cells
    const int yOffset = 500; // vertical offset of the living cells
    
    // living cells
    std::vector<cell> livingCells = {{0, 0}, {1,0}, {-1,1}, {0,1}}; 
    
    
    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");
    SetTargetFPS(60);
    std::cout << countNeighborCells(&livingCells, livingCells[0]) << std::endl;

    
    while(!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            drawLivingCells(&livingCells, xOffset, yOffset, cellDimension);

        EndDrawing();
    }
    
    CloseWindow();
    
}

//g++ main.cpp conway_func.cpp -o conway -IC:\libraries\raylib\raylib\src -LC:\libraries\raylib\raylib\src -lraylib -lopengl32 -lwinmm -lgdi32
