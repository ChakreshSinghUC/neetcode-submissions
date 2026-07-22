class Solution {
private:
    void buildCombinations(
        string& digits,
        int index,
        vector<string>& mapping,
        string& current,
        vector<string>& ans
    ) {
        // We selected one letter for every digit.
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (char ch : letters) {
            current.push_back(ch);

            buildCombinations(
                digits,
                index + 1,
                mapping,
                current,
                ans
            );

            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) {
            return ans;
        }

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;

        buildCombinations(
            digits,
            0,
            mapping,
            current,
            ans
        );

        return ans;
    }
};