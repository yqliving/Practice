class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(sum - target);
        int n = nums.size();
        int result = sum;
        
        for (int i = 0; i < n-2; i++) {
            int first = i + 1;
            int second = n - 1;
            
            while (first < second) {
                int sum = nums[i] + nums[first] + nums[second];
                int diff = abs(sum - target);
                if (diff == 0) return sum;
                
                if (diff < minDiff) {
                    minDiff = diff;
                    result = sum;
                } 
                if (sum - target > 0) 
                    second --;
                else 
                    first ++;
            }
        }
        return result;
        
    }
};
