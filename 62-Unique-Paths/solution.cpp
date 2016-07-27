class Solution {  
public:  
    int uniquePaths(int m, int n) {  
        vector<vector<int>> v(m, vector<int>(n, 1));  
        for(int i=1; i<m; ++i){  
            for(int j=1; j<n; ++j){  
                v[i][j]=v[i-1][j]+v[i][j-1];  
            }  
        }  
        return v[m-1][n-1];  
    }  
};  

//动态规划，定义一个二维数组 A[M][N]，从左上开始依次计算每一行的值，最后返回 A[M-1][N-1]即可，递推方程是：A[I][J]=A[I-1][J]+A[I][J-1]；
