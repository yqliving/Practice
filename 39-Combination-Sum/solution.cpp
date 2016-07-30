class Solution {
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        help (candidates, target, 0, res, cur);
        return res;
    }
    void help(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            //return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i ++) {
                cur.push_back(candidates[i]);
                help (candidates, target - candidates[i], i, res, cur);
                cur.pop_back();
            }
    }
};
//recurrion

/*class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    int size = candidates.size();
    if (size == 0) return result;
    sort(candidates.begin(), candidates.end());
    vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
    dp[0].push_back(vector<int>());

    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < size && candidates[j] <= i; ++j) {
            for (int k = 0; k < dp[i - candidates[j]].size(); ++k) {
                vector<int> temp = dp[i - candidates[j]][k];
                if (temp.size() && (temp[temp.size() - 1] > candidates[j])) continue;
                temp.push_back(candidates[j]);
                dp[i].push_back(temp);
            }
        }
    }
    return dp[target];
}
};

