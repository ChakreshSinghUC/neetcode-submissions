class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) {
            return s.length();
        }

        unordered_map<char, int> lastSeenCharacterIndex;
        int eligibleSubstringStartingIndex = 0;
        int lengthOfCurrentEligibleSubstring = 0;
        int lengthOfLongestSubstring = INT_MIN;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeenCharacterIndex.find(s[i]) != lastSeenCharacterIndex.end()) {
                if (lastSeenCharacterIndex[s[i]] >= eligibleSubstringStartingIndex) {
                    eligibleSubstringStartingIndex = lastSeenCharacterIndex[s[i]] + 1;
                }
            }
            lastSeenCharacterIndex[s[i]] = i;

            lengthOfCurrentEligibleSubstring = i - eligibleSubstringStartingIndex + 1;
            lengthOfLongestSubstring =
                max(lengthOfLongestSubstring, lengthOfCurrentEligibleSubstring);
        }

        return lengthOfLongestSubstring;
    }
};
