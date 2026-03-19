#pragma once
#include "grid.hpp"

class Simulation {
    public:
        Simulation(int width, int height, int cellSize) : grid(width, height, cellSize), temporaryGrid(width, height, cellSize), running(false) {grid.FillRandomCells();};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column); 
        void Update();
        bool IsRunning();
        void StartSimulation();
        void StopSimulation();
    private:
        Grid grid;
        Grid temporaryGrid;
        bool running;
};