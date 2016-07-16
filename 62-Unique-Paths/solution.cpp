class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(2, vector<int>(n, 1));
    int idx = 1;
    for (int i = 1; i < m; i++, idx = 1 - idx) {
        for (int j = 1; j < n; j++) {
            dp[idx][j] = dp[idx][j - 1] + dp[1 - idx][j];
        }
    }
    return dp[1 - idx][n - 1];
}
};