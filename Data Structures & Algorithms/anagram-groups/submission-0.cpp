class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (auto s : strs) {
            string copy = s;
            sort(s.begin(), s.end());
            if (mp.find(s) != mp.end()) {
                mp[s].push_back(copy);
            } else {
                mp[s] = {copy};
            }
        }

        for (auto m : mp) {
            ans.push_back(m.second);
        }

        return ans;
    }
};
