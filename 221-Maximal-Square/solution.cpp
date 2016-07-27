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
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
                //tracking the maxSize
               
            }
        }
        return maxSize*maxSize;
    }
};

/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int lenR = matrix.size();
        int lenC = matrix[0].size();
        
        vector<vector<int>> D(lenR, vector<int>(lenC));  //注意初始化的形式，不能写成D（lenR，lenC）
        int maxVal = 0;
        
        for (int i = 0; i < lenR; i++) {
            if (matrix[i][0] == '1') {
                D[i][0] = 1;
                maxVal = 1;
            }
        }
        for (int j = 0; j < lenC; j++) {
            if (matrix[0][j] == '1') {
                D[0][j] = 1;
                maxVal = 1;
            }
        }
        for (int i = 1; i < lenR; i ++) {
            for (int j = 1; j < lenC; j ++) {
                if (matrix[i][j] == '0') D[i][j] = 0;
                else {
                    D[i][j] = min(min(D[i-1][j], D[i][j-1]), D[i-1][j-1]) + 1;
                    maxVal = max(maxVal, D[i][j]);
                }
            }
        }
        return maxVal*maxVal;
    }
};/*
