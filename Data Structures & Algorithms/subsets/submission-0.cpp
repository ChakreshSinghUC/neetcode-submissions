class Solution {
    vector<vector<int>> ans;

    void dfs(int index, vector<int>& current, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Include nums[index]
        current.push_back(nums[index]);
        dfs(index + 1, current, nums);

        current.pop_back();
        // Exclude nums[index]
        dfs(index + 1, current, nums);
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        dfs(0, current, nums);
        return ans;
    }
};
