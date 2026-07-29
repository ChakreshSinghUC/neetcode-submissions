class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLength = 1;

        // i must move backward because dp[i][j]
        // depends on dp[i + 1][j - 1].
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    int currentLength = j - i + 1;

                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};