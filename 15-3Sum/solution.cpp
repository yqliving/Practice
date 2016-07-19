class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] = nums[i-1]) continue;
            int a = nums[i];
            int left = i + 1;
            int right = len - 1;
            while(left < right) {
                int b = nums[left];
                int c = nums[right];
                if (a + b + c == 0) {
                    res.push_back(vector<int> {a, b, c});
                    
                    while (left < len && nums[left] == b) left++;
                    while (right > 0 && nums[right] == c) right --;
                }
                else if (a + b + c > 0) right --;
                else left --;
            }
        }
        return res;
        
    }
};
