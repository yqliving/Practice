class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int lenR = grid.size();
        int lenC = grid[0].size();
        
        for (int i = 0; i <lenR; i ++) {
            for (int j = 0; j < lenC; j++) {
                int top  = (i - 1) < 0 ? INT_MAX : grid[i-1][j];
                int left = (j - 1) < 0 ? INT_MAX : grid[i][j-1];
                if (top == INT_MAX && left == INT_MAX) continue;
                grid[i][j] += top < left ? top : left;
            }
        }
        return grid[lenR - 1][lenC - 1];
    }
};

/*2-d DP: Time ~ O(N^2), Space ~ O(M*N)
Let d(i,  j) be the min path sum from grid[0,  0] (top left) to grid[i, j].
d(i, j) = min{d(i - 1, j), d(i, j - 1)} + grid[i, j];
Return d(M - 1, N - 1).
Use top-down approach.

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return INT_MIN;
        int M = grid.size(), N = grid[0].size();
        int dp[N];
        dp[0] = grid[0][0];
        for (int i = 1; i < N; ++i)
            dp[i] = grid[0][i] + dp[i-1];
        
        for (int i = 1; i < M; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < N; ++j)
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
        
        return dp[N-1];
    }
};

