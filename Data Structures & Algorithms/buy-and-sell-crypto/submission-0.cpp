class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPurchasePrice = INT_MAX;
        int currProfit = 0;
        int maxProfit = 0;

        for(auto p :prices) {
            if(p<lowestPurchasePrice){
                lowestPurchasePrice = p;
            }
            else {
                currProfit = p-lowestPurchasePrice;
            }
            maxProfit = max(maxProfit, currProfit);
        }

        return maxProfit;
    }
};
