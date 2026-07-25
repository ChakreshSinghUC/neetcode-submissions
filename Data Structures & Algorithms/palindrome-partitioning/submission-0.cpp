class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(
        const string& s,
        int left,
        int right
    ) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void dfs(
        const string& s,
        int start,
        vector<string>& current
    ) {
        // Entire string has been partitioned
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every substring beginning at start
        for (int end = start; end < s.size(); end++) {

            // Ignore this choice if it is not a palindrome
            if (!isPalindrome(s, start, end)) {
                continue;
            }

            // Choose
            current.push_back(
                s.substr(start, end - start + 1)
            );

            // Recurse on the remaining string
            dfs(s, end + 1, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;

        dfs(s, 0, current);

        return ans;
    }
};