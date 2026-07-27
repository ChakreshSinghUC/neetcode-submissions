class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int maxFrequency = 0;
        int mostFrequentNumber = nums[0];
        unordered_map<int, int> mp;
        for (auto n : nums) {
            if (mp.find(n) != mp.end()) {
                mp[n]++;
            } else {
                mp[n] = 1;
            }
            if( mp[n]> maxFrequency){
                maxFrequency = mp[n];
                mostFrequentNumber = n;
            }
        }

        return mostFrequentNumber;
    }
};