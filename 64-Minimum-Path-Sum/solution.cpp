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
                grid[i][j] += min(top, left);
            }
        }
        return grid[lenR - 1][lenC - 1];
    }
};

/* 首先可以找出递推关系，比如设存放起点到每个格子 i，j 的最小路径和的二维数组为 MPS[i][j]，那么递推公式为：

    MPS[i][j] = Min（MPS[i-1][j]，MPS[i][j-1]）+ val[i][j]；
   
    即格子 i，j 的MPS值可能有两个来源：其左侧格子 i，j-1 或者其上侧格子 i-1，j ；取这两个来源的较小MPS值，再加上当前格子的值 val[i][j] 即为结果。

    设N为格子总数（N=m*n），上面的代码空间复杂度为O(N)，时间复杂度为O(N)