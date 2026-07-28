class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;

        int bestStart = 0;
        int bestLength = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char added = s[right];
            window[added]++;

            // This required character has just become satisfied.
            if (need.count(added) &&
                window[added] == need[added]) {
                formed++;
            }

            // The window currently contains everything required.
            while (formed == required) {
                int currentLength = right - left + 1;

                if (currentLength < bestLength) {
                    bestLength = currentLength;
                    bestStart = left;
                }

                char removed = s[left];

                // Removing this character will break a requirement.
                if (need.count(removed) &&
                    window[removed] == need[removed]) {
                    formed--;
                }

                window[removed]--;
                left++;
            }
        }

        if (bestLength == INT_MAX) {
            return "";
        }

        return s.substr(bestStart, bestLength);
    }
};