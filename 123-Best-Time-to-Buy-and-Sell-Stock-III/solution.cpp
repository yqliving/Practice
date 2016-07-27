//题意：用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。最多交易两次，手上最多只能持有一支股票，求最大收益。

//分析：动态规划法。以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]，最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。

//代码：时间O(n)，空间O(n)。
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> pre, post;
        
        int curMin = INT_MAX;
        for (int i = 1; i < len; i++) {
            curMin = min(curMin, prices[i]);
            pre[i] = max(pre[i - 1], prices[i] - curMin);
        }
        int curMax = INT_MIN;
        for (int j = len - 2; j >= 0; j--) {
            curMax = max(curMax, prices[j]);
            post[j] = max(post[ j + 1], curMax - prices[j]);
        }
        
        int maxVal = 0;
        for (int i = 0; i < len; i ++) {
            maxVal = max(maxVal, pre[i] + post[i]);
        }
        
        return maxVal;
    }
    
};


/*It is similar to other buy/sell problems. just do DP and define an array of states to track the current maximum profits at different stages. For example, in the below code

states[][0]: one buy
states[][1]: one buy, one sell
states[][2]: two buys, one sell
states[][3]: two buy, two sells
The states transistions occurs when buy/sell operations are executed. For example, state[][0] can move to state[][1] via one sell operation.
*/
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int states[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
        int len = prices.size(), i, cur = 0, next =1;
        for(i=0; i<len; ++i)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0]+prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1]-prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2]+prices[i]);
            swap(next, cur);
        }
        return max(states[cur][1], states[cur][3]);
    }
};