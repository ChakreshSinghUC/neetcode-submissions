class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // Stores indices
        vector<int> result;

        for (int right = 0; right < nums.size(); right++) {

            // Remove elements weaker than the new element.
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            int left = right - k + 1;

            // Remove the maximum if it is outside the window.
            if (dq.front() < left) {
                dq.pop_front();
            }

            // A complete window has now been formed.
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};