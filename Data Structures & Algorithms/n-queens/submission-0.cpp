class Solution {
public:
    vector<vector<string>> ans;

    unordered_set<int> columns;
    unordered_set<int> negativeDiagonal;  // row - col
    unordered_set<int> positiveDiagonal;  // row + col

    void dfs(
        int row,
        int n,
        vector<string>& board
    ) {
        // We successfully placed one queen in every row
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing the queen in every column of this row
        for (int col = 0; col < n; col++) {

            // This position is attacked by an existing queen
            if (
                columns.count(col) ||
                negativeDiagonal.count(row - col) ||
                positiveDiagonal.count(row + col)
            ) {
                continue;
            }

            // Choose
            board[row][col] = 'Q';
            columns.insert(col);
            negativeDiagonal.insert(row - col);
            positiveDiagonal.insert(row + col);

            // Recurse to the next row
            dfs(row + 1, n, board);

            // Undo
            board[row][col] = '.';
            columns.erase(col);
            negativeDiagonal.erase(row - col);
            positiveDiagonal.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(
            n,
            string(n, '.')
        );

        dfs(0, n, board);

        return ans;
    }
};