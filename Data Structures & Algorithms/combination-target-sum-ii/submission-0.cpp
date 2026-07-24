class Solution {
    vector<vector<int>> ans;

    void backtrack(int start, int target, vector<int>& current, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) {
                break;
            }

            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(i + 1, target - nums[i], current, nums);

            current.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, current, candidates);
        return ans;
    }
};
