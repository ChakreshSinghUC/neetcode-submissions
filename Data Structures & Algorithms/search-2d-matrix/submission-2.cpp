class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;

        int mid = l + (r-l)/2;

        while(l<=r) {
            if(target == matrix[mid][0]) {
                return true;
            }
            if(target < matrix[mid][0]) {
                r = mid-1;
            } else if(target > matrix[mid][0]) {
                l = mid+1;
            }
             mid = l + (r-l)/2;
        }

        // r is now the last row whose first element is <= target.
        if (r < 0) {
            return false;
        }

        vector<int> row(matrix[r].begin(), matrix[r].end());
        l = 0;
        r = row.size()-1;
        mid = l + (r-l)/2;
        while (l<=r){
            if(target == row[mid]) {
                return true;
            }
            if(target < row[mid]) {
                r = mid-1;
            } else if(target > row[mid]) {
                l = mid+1;
            }
             mid = l + (r-l)/2;
        }

        return false;
    }
};
