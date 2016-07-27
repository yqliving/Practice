//在1-n个数里面，我们任意猜一个数(设为i)，保证获胜所花的钱应该为 i + max(w(1 ,i-1), w(i+1 ,n))，这里w(x,y))表示猜范围在(x,y)的数保证能赢应花的钱，则我们依次遍历 1-n作为猜的数，求出其中的最小值即为答案，即最小的最大值问题
class Solution {  
public:  
   int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (int k = j; k <= i; ++k){
                    int tmp = k + max(dp[j][k - 1], dp[k + 1][i]);
                    min_value = min(min_value, tmp);
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
    }
};  