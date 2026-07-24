class Solution {
    vector<vector<int>> ans;

    void backtrack(int start, int target, vector<int>& current, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i, target - nums[i], current, nums);

            current.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;

        backtrack(0, target, current, nums);
        return ans;
    }
};
