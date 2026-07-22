class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxarea = INT_MIN;

        int l = 0;
        int h = heights.size() - 1;

        for (int i = 0; i < heights.size() - 1; i++) {
            for (int j = 1; j < heights.size(); j++) {
               // cout<<maxarea<<"\t"<<min(heights[i], heights[j]) * (j - i)<<endl;
                maxarea = max(maxarea, min(heights[i], heights[j]) * (j - i));
            }
        }
        return maxarea;
    }
};
