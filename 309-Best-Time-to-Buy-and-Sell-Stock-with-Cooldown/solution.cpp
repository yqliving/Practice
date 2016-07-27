class Solution {
public:
int maxProfit(vector<int>& p) 
{
    if (p.size() < 2)
        return 0;
    int i, sz = p.size();
    int ret = 0;
    vector<int> buy(sz, 0);
    vector<int> sell(sz, 0);
    buy[0] = -p[0];
    for (i = 1; i < sz; ++i)
    {
        sell[i] = max(buy[i - 1] + p[i], sell[i - 1] - p[i - 1] + p[i]);
        if (ret < sell[i]) //record the max sell[i]
            ret = sell[i];
        if (1 == i)
            buy[i] = buy[0] + p[0] - p[1];
        else
            buy[i] = max(sell[i - 2] - p[i], buy[i - 1] + p[i - 1] - p[i]);
    }
    return ret;
}
};
/*buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; 
  sell[i-1]-prices[i-1]+prices[i] represents you didn't sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).
  sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown). 
  buy[i-1]+prices[i-1]-prices[i] means you didn't buy the stock on day i-1 but buy it on day i.


/*class Solution {
public:
    int maxProfit(vector<int>& prices) 
{
    int buy= INT_MIN, sell_1=0,sell_2=0;

    for (int i = 0; i < prices.size(); ++i)
    {
        buy =  i < 3 ? max(-prices[i], buy):max(sell_2-prices[i], buy);

        sell_2 = sell_1;

        sell_1 = max(sell_1, buy + prices[i]);
    }

    return sell_1;
}
};
//Dynamic programming