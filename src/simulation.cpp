#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) {
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets =
    {
        // Format: {+/- row, +/- column}
        {-1, 0}, // Above
        {1, 0}, // Below
        {0, -1}, // Left
        {0, 1}, // Right
        {-1, -1}, // Upper Left
        {-1, 1}, // Upper Right
        {1, -1}, // Lower Left
        {1, 1} // Lower Right
    };

    for (const auto& offset : neighborOffsets) {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}