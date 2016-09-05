class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    int count = 0;
    for(int i = 0; i < grid.size(); ++i)
        for(int j = 0; j < grid[i].size(); ++j)
            if(grid[i][j] == '1'){
                ++count;
                helper(grid, i, j);
            }
    return count;
}

void helper(vector<vector<char>>& grid, int row, int col){
    if(row < 0 || col < 0 || row == grid.size() || col == grid[row].size()) return ;
    if(grid[row][col] == '1') {
        grid[row][col] = '0';
        helper(grid, row - 1, col);
        helper(grid, row + 1, col);
        helper(grid, row, col - 1);
        helper(grid, row, col + 1);
    }
    return ;
}
};



//DFS: Time ~ O(MN), Space ~ O(MN) 
//对每个为 '1' 的点使用 DFS，访问所有与其连接的 '1'，并将 '1' 标记为 '#'。每完成一次 DFS 就得到一个 island
