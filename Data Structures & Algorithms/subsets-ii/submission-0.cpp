class Solution {
   public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int>& current, const vector<int>& nums) {
        // assumes nums is sorted
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // 1. include branch
        // do not skip duplicates on the include branch
        current.push_back(nums[index]);

        // if the next number is duplicate, its treated as a new entry
        dfs(index + 1, current, nums);

        current.pop_back();

        // 2. exclude branch
        // skip duplicates on the exclude branch

        int nextIndex = index + 1;

        // duplicates get excluded before landing on a new number
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }

        dfs(nextIndex, current, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        dfs(0, current, nums);
        return ans;
    }
};
