class Solution {
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        help (candidates, target, 0, res, cur);
        return res;
    }
    void help(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int>& cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i ++) {
            if (i != start && candidates[i] == candidates[i-1]) continue; // this line ensures no duplicate
                cur.push_back(candidates[i]);
                help (candidates, target - candidates[i], i+1, res, cur); // should be i+1
                cur.pop_back();
            }
    }
};


