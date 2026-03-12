#include <raylib.h>

int main() 
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    int FPS = 12;
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS); // acts as an fps cap
    
    // Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event Handling
        
        // 2. Updating State

        // 3. Drawing

        BeginDrawing();
        ClearBackground(GREY);
        EndDrawing();
    }

    CloseWindow();
}