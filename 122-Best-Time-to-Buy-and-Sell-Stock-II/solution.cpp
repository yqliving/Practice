class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if (prices.size()==0) return 0;
    int profit = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            int diff = prices[i + 1] - prices[i];
            if (diff > 0)   profit += diff;
        }
        return profit;   
    }
};