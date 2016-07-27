//在1-n个数里面，我们任意猜一个数(设为i)，保证获胜所花的钱应该为 i + max(w(1 ,i-1), w(i+1 ,n))，这里w(x,y))表示猜范围在(x,y)的数保证能赢应花的钱，则我们依次遍历 1-n作为猜的数，求出其中的最小值即为答案，即最小的最大值问题
class Solution {  
public:  
    int getMoneyAmount(int n) {  
        vector<vector<int>> pay(n + 1, vector<int>(n));  
        for (int i = n - 1; i >= 0; --i) {  
            for (int j = i + 1; j < n; ++j) {  
                pay[i][j] = numeric_limits<int>::max();  
                for (int k = i; k <= j; ++k) {  
                    pay[i][j] = min(pay[i][j], k + 1 + max(pay[i][k - 1], pay[k + 1][j]));  
                }  
            }  
        }  
        return pay[0][n - 1];  
    }  
};  