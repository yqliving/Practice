
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findStart(nums, target), end = findEnd(nums, target);
        return {start, end};
    }
    int findStart(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return nums[l] == target ? l : -1;
    }
    int findEnd(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + 1 + (r - l)/2;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return nums[l] == target ?  l :  -1;
    }
};
// 确定左边时， mid = l + (r - l)/2; 确定右边时，mid = l + 1 + (r - l)/2;
// for example: [2,2], 2. If I only use mid for one time, the output will be [1, 1], but the expected result is [0, 1]
