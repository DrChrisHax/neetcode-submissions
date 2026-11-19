class Solution {
public:
    int maxProfit(vector<int>& prices) {

        size_t left = 0;
        size_t right = 1;

        int bestProfit = 0;

        while(right < prices.size())
        {
            int profit = prices[right] - prices[left];

            if(profit <= 0)
            {
                left = right;
                right += 1;
            }
            else
            {
                right += 1;
                bestProfit = std::max(profit, bestProfit);
            }
        }

        return bestProfit;
    }
};
