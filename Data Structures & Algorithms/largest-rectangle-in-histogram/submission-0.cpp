class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        // pair = {startIndex, height}

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();

                int width = i - index;
                int area = height * width;

                maxArea = max(maxArea, area);

                // Current shorter bar can extend back
                // to where the popped taller bar started.
                start = index;
            }

            st.push({start, heights[i]});
        }

        // Bars left in the stack can extend to the end.
        int n = heights.size();

        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();

            int width = n - index;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};