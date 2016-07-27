class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};

/* 此题需要维护三个一维数组buy, sell，和rest。其中：

buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。

sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。

rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。

我们写出递推式为：

buy[i]  = max(rest[i-1] - price, buy[i-1]) 
sell[i] = max(buy[i-1] + price, sell[i-1])
rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

由于冷冻期的存在，我们可以得出rest[i] = sell[i-1]，这样，我们可以将上面三个递推式精简到两个：

buy[i]  = max(sell[i-2] - price, buy[i-1]) 
sell[i] = max(buy[i-1] + price, sell[i-1])


//=============
/*buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; 
  sell[i-1]-prices[i-1]+prices[i] represents you didn't sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).
  sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown). 
  buy[i-1]+prices[i-1]-prices[i] means you didn't buy the stock on day i-1 but buy it on day i.



//Dynamic programming