class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //if (prices.size() < 2) return 0;
        int curMin = INT_MAX;
        int maxValue = 0;
        
        for (int i = 0; i < prices.size(); i++) {
           curMin = min(curMin, prices[i]);
           maxValue = max(maxValue, prices[i] - curMin);
        }
        return maxValue;
    }
};

/*// This solution is O(1) space dynamic programming 
    //
    // We can make sure the max profit at least be ZERO. So,
    //    1) we have two pointers (begin & end ) 
    //    2) if prices[end] - prices[begin] >  0, then move the "end" pointer to next
    //    3) if prices[end] - prices[begin] <= 0, then move the "begin" pointer to current posstion.
    //    4) tracking the max profit
    //
    // Notes:
    //    Some people think find the highest-price & lowest-price, this is wrong. 
    //    Because the highest-price must be after lowest-price
    //