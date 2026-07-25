class Solution {
    vector<string> ans;

    void dfs(int open, int close, int n, string& current) {
        if (open == close && open == n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            dfs(open + 1, close, n, current);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            dfs(open, close + 1, n, current);
            current.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        string current;
        dfs(0, 0, n, current);
        return ans;
    }
};
