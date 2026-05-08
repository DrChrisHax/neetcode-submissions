class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowestPrice = prices[0];
        int bestProfit = 0;

        for (std::size_t i = 1; i < prices.size(); ++i) {
            int val = prices[i];

            lowestPrice = std::min(lowestPrice, val);
            bestProfit = std::max(bestProfit, val - lowestPrice);
        }

        return bestProfit;
    }
};
