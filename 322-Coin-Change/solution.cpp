class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
{
	vector<int> amountToNumCoins(amount + 1, INT_MAX);
	amountToNumCoins[0] = 0;

	for (int coin : coins)
	{
		for (int i = coin; i <= amount; ++i)
		{
			int prev = i - coin;
			if (amountToNumCoins[prev] != INT_MAX)
			{
				amountToNumCoins[i] = min(amountToNumCoins[i], amountToNumCoins[prev] + 1);
			}
		}
	}

	return (amountToNumCoins[amount] == INT_MAX) ? -1 : amountToNumCoins[amount];
}
};

/*class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //int Max = amount + 1;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

