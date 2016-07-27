//dynamic programing.  以当前点(x,y) = '1' 为右下角的最大正方形的边长f(x,y) = min( f(x-1,y), f(x,y-1), f(x-1,y-1)) + 1. 递推公式已建立, dp就自然而然了.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int maxSize = 0;
        vector<vector<int>> dp(row, vector<int>(col));
        
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++){
                //convert the `char` to `int`
                dp[i][j] = matrix[i][j] -'0';
                //for the first row and first column, or matrix[i][j], dp[i][j] is ZERO
                //so, it's done during the previous conversion
                
                // i>0 && j>0 && matrix[i][j]=='1'
                if (i!=0 && j!=0 & dp[i][j]!=0){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
                //tracking the maxSize
               
            }
        }
        return maxSize*maxSize;
    }
};

