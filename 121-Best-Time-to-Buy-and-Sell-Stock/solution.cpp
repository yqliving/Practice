class Solution {
public:
    int maxProfit(vector<int> &prices) {

        int curMin = INT_MAX;
        int maxValue = 0;
        
        for (int i = 0; i < prices.size(); i++) {
           curMin = min(curMin, prices[i]);
           maxValue = max(maxValue, prices[i] - curMin);
        }
        return maxValue;
    }
};

//动态规划法。从前向后遍历数组，记录当前出现过的最低价格，作为买入价格，并计算以当天价格出售的收益，作为可能的最大收益，整个遍历过程中，出现过的最大收益就是所求。

