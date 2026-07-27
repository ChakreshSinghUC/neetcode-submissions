class Solution {
    int lcp(string s1, string s2) {
        if(s1.empty() || s2.empty())
        {
            return 0;
        }
        int lcp = 0;

        while (s1[lcp] == s2[lcp]) {
            lcp++;
            if (lcp == min(s1.length(), s2.length())) {
                break;
            }
        }
        return lcp;
    }

   public:
    string longestCommonPrefix(vector<string>& strs) {
        int lengthOfLCP = INT_MAX;
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        for (int i = 1; i < strs.size(); i++) {
            lengthOfLCP = min(lengthOfLCP, lcp(strs[i], strs[i - 1]));
            if (lengthOfLCP == 0) {
                return "";
            }
        }
        
        return strs[0].substr(0, lengthOfLCP);
    }
};