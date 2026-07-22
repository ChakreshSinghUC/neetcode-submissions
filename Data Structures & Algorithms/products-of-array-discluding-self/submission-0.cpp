class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts;
        vector<int> suffixProducts;

        int curr = 1;
        for (int i = 0; i < nums.size(); i++) {
            cout<<curr<<endl;
            prefixProducts.push_back(curr);
            curr *= nums[i];
        }

        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            cout<<curr<<endl;
            suffixProducts.push_back(curr);
            curr *= nums[i];
        }

        //reverse(suffixProducts.begin(), suffixProducts.end());

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(prefixProducts[i] * suffixProducts[nums.size()-1-i]);
        }

        return ans;
    }
};
