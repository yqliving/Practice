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
            if (i != start && candidates[i] == nums[i-1]) continue;
                cur.push_back(candidates[i]);
                help (candidates, target - candidates[i], i, res, cur);
                cur.pop_back();
            }
    }
};

