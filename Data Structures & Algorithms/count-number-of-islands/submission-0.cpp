class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        vector<pair<int, int>> directions = {
            {-1, 0},  // up
            {1, 0},   // down
            {0, -1},  // left
            {0, 1}    // right
        };

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (grid[row][col] == '1') {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({row, col});

                    // Mark visited immediately.
                    grid[row][col] = '0';

                    while (!q.empty()) {
                        auto [currentRow, currentCol] = q.front();
                        q.pop();

                        for (auto [dr, dc] : directions) {
                            int newRow = currentRow + dr;
                            int newCol = currentCol + dc;

                            if (newRow >= 0 && newRow < rows &&
                                newCol >= 0 && newCol < cols &&
                                grid[newRow][newCol] == '1') {

                                grid[newRow][newCol] = '0';
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};