#include "conway_func.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawRectangle(screenWidth/2, screenHeight/2, 15, 15, MAROON);
        EndDrawing();
    }
    
    CloseWindow();
}

//g++ main.cpp conway_func.cpp -o conway -IC:\libraries\raylib\raylib\src -LC:\libraries\raylib\raylib\src -lraylib -lopengl32 -lwinmm -lgdi32
