class Solution {
    public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, temp, 1, k, n);
    return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int start, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(temp);
            return;
        }
        if (start > 9 || start > n) return;
        for (int i = start; i < 10; i++) {
        temp.push_back(i);    //i 不是 start
        dfs(res, temp, i+1, k - 1, n - i);      
           //这是i+1， 如果是i，结果是：[[1,1,5],[1,2,4],[1,3,3],[2,2,3]]
        temp.pop_back();
        }
    }
};




