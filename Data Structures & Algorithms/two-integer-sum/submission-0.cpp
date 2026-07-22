class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // number -> index
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            auto it = seen.find(needed);

            if (it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};