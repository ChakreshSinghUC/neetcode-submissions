class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int trappedWater = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                } else {
                    trappedWater += leftMax - height[l];
                }

                l++;
            } else {
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                } else {
                    trappedWater += rightMax - height[r];
                }

                r--;
            }
        }

        return trappedWater;
    }
};