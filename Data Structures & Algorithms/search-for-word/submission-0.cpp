class Solution {
public:
    int rows;
    int cols;

    bool dfs(
        vector<vector<char>>& board,
        const string& word,
        int row,
        int col,
        int index
    ) {
        // Entire word has been matched
        if (index == word.size()) {
            return true;
        }

        // Invalid board position
        if (
            row < 0 ||
            row >= rows ||
            col < 0 ||
            col >= cols
        ) {
            return false;
        }

        // Current cell does not match current word character
        if (board[row][col] != word[index]) {
            return false;
        }

        // Choose this cell
        char original = board[row][col];
        board[row][col] = '#';

        // Choice 1: move up
        if (dfs(board, word, row - 1, col, index + 1)) {
            board[row][col] = original;
            return true;
        }

        // Choice 2: move down
        if (dfs(board, word, row + 1, col, index + 1)) {
            board[row][col] = original;
            return true;
        }

        // Choice 3: move left
        if (dfs(board, word, row, col - 1, index + 1)) {
            board[row][col] = original;
            return true;
        }

        // Choice 4: move right
        if (dfs(board, word, row, col + 1, index + 1)) {
            board[row][col] = original;
            return true;
        }

        // Undo the choice
        board[row][col] = original;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};