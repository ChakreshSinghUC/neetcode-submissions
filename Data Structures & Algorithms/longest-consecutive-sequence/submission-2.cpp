class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int maxLength = 0;

        for (int n : s) {
            // Only begin at the start of a sequence
            if (s.find(n - 1) == s.end()) {
                int current = n;
                int currLen = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    currLen++;
                }

                maxLength = max(maxLength, currLen);
            }
        }

        return maxLength;
    }
};