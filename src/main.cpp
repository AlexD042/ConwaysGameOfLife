#include <raylib.h>
#include "grid.hpp"

int main() 
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 32; // window height or width divided by 25
    int FPS = 12; // acts as the highest fps the simulation will run at
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS);
    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event Handling
        
        // 2. Updating State

        // 3. Drawing

        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}