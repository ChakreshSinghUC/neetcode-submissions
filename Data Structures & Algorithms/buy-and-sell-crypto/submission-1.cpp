class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPurchasePrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            lowestPurchasePrice = min(lowestPurchasePrice, price);

            int currentProfit = price - lowestPurchasePrice;
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};