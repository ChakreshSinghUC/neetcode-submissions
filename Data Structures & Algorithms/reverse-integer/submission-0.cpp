class Solution {
   public:
    int reverse(int x) {
        queue<int> s;

        while (x) {
            s.push(x % 10);
            x /= 10;
        }

        long long ans = 0;
        while (!s.empty()) {
            ans = ans * 10 + s.front();
            s.pop();
        }

        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return ans;
    }
};
