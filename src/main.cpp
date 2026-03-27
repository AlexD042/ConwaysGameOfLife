#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

// Rules for Conway's Game of Life
// 1. Underpopulation: Any live cell with fewer than two live neighbours dies
// 2. Survival: Any live cell with two or three live neighbours lives on to the next generation
// 3. Overpopulation: Any live cell with more than three live neighbours dies
// 4. Reproduction: Any dead cell with exactly three live neighbours becomes a live cell

// Simplified Rules
// 1. If a cell is alive, it will die when it has fewer than 2 or more than 3 living neighbors, otherwise it lives
// 2. Any dead cell with exactly three live neighbours becomes a live cell

int main() 
{
    const int WINDOW_WIDTH =  1200;
    const int WINDOW_HEIGHT = 800;
    const int CELL_SIZE = 5; // window height or width divided by 25
    int FPS = 12;
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life [STOPPED]");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // Simulation Loop
    while(WindowShouldClose() == false) {
        // 1. Event Handling
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }
        
        if(IsKeyPressed(KEY_SPACE)) {
            if (simulation.IsRunning()) {
                simulation.StopSimulation();
                SetWindowTitle("Conway's Game of Life [STOPPED]");
            }
            else {
                simulation.StartSimulation();
                SetWindowTitle("Conway's Game of Life [RUNNING]");
            }
        }
        else if (IsKeyPressed(KEY_UP)) {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_DOWN) && FPS > 3) {
            FPS -= 2;
            SetTargetFPS(FPS);
        }
        else if(IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        // 2. Updating State
        simulation.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}