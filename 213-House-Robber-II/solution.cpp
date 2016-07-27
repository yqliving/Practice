/*This solution is based on house robber 1. The idea is that either the first house or the last house is not robbed. The final solution is max of (house robber without last element) and (house robber without the first element). Note endIndex is not inclusive in the second rob function.
*/
class Solution {
public:
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    
    return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
}

int rob(vector<int>& nums, int startIndex, int endIndex) {
    int p = 0, q = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        int tmp = p;
        p = max(p, q + nums[i]);
        q = tmp;
    }
    return p;
}
};
// House Robber I的升级版. 因为第一个element 和最后一个element不能同时出现. 则分两次call House Robber I. case 1: 不包括最后一个element. case 2: 不包括第一个element.