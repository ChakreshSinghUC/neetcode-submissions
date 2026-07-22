class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <2) {
            return nums.size();
        }
        set<int> s;
        
        for(auto n : nums) {
            s.insert(n);
        }

        int maxLength = INT_MIN;

        for(auto n : nums){
            
            int currLen = 1;

            while(s.find(n+1) != s.end()){
                currLen++;
                n++;
            }
            maxLength = max(maxLength, currLen);
        }

        return maxLength;
    }
};
