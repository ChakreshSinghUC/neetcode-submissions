class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char value = board[row][col];

                if (value == '.') {
                    continue;
                }

                int boxIndex = (row / 3) * 3 + (col / 3);

                if (rows[row].count(value) ||
                    cols[col].count(value) ||
                    boxes[boxIndex].count(value)) {
                    return false;
                }

                rows[row].insert(value);
                cols[col].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;
    }
};