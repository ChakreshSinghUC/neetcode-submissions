class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        int windowSize = s1.length();

        // Build frequency counts for s1 and the first window of s2
        for (int i = 0; i < windowSize; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }

        if (s1Count == windowCount) {
            return true;
        }

        // Slide the window through s2
        for (int right = windowSize; right < s2.length(); right++) {
            // Add the new right-side character
            windowCount[s2[right] - 'a']++;

            // Remove the character leaving from the left
            int left = right - windowSize;
            windowCount[s2[left] - 'a']--;

            if (s1Count == windowCount) {
                return true;
            }
        }

        return false;
    }
};