class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 0) return 0;
        int maxn, temp;
        maxn = temp = nums[0];
        for (int i = 1; i < len; i++) {
            temp = max(nums[i], temp + nums[i]);
            maxn = max(maxn, temp);
        }
        return maxn;
    }
};


/*O(1)space,O(N)time