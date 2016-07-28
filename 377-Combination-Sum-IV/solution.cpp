class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target + 1);
        result[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) {
                    result[i] += result[i - x];
                }
            }
        }
        
        return result[target];
    }
};
// 状态转移方程：dp[x + y] += dp[x].
// 其中dp[x]表示生成数字x的所有可能的组合方式的个数。