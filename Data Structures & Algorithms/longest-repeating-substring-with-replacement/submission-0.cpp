class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequency;

        int left = 0;
        int maxFrequency = 0;
        int longest = 0;

        for (int right = 0; right < s.length(); right++) {
            frequency[s[right]]++;

            maxFrequency =
                max(maxFrequency, frequency[s[right]]);

            int windowLength = right - left + 1;
            int replacementsNeeded = windowLength - maxFrequency;

            while (replacementsNeeded > k) {
                frequency[s[left]]--;
                left++;

                windowLength = right - left + 1;
                replacementsNeeded =
                    windowLength - maxFrequency;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};