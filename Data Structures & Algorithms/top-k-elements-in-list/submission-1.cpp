class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int n : nums) {
            frequency[n]++;
        }

        // buckets[count] contains numbers appearing "count" times
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [value, count] : frequency) {
            buckets[count].push_back(value);
        }

        vector<int> ans;

        for (int count = nums.size(); count >= 1; count--) {
            for (int value : buckets[count]) {
                ans.push_back(value);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};