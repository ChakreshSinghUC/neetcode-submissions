class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Add boundary land cells from first and last columns.
        for (int row = 0; row < rows; row++) {
            if (grid[row][0] == 1) {
                q.push({row, 0});
                grid[row][0] = 0;
            }

            if (grid[row][cols - 1] == 1) {
                q.push({row, cols - 1});
                grid[row][cols - 1] = 0;
            }
        }

        // Add boundary land cells from first and last rows.
        for (int col = 0; col < cols; col++) {
            if (grid[0][col] == 1) {
                q.push({0, col});
                grid[0][col] = 0;
            }

            if (grid[rows - 1][col] == 1) {
                q.push({rows - 1, col});
                grid[rows - 1][col] = 0;
            }
        }

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1) {

                    grid[newRow][newCol] = 0;
                    q.push({newRow, newCol});
                }
            }
        }

        int enclaves = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};