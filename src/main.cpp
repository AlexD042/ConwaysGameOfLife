#include <raylib.h>
#include "grid.hpp"

int main() 
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 32; // window height or width dived by 25
    int FPS = 12;
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS); // acts as an fps cap
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