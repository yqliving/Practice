
class Solution {
    public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left]) left ++;
            else if (nums[mid] > nums[left]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
    
    
};

/*
The only difference here comparing to "33. Search in Rotated Sorted Array(Hard)" is to add a separate condition check for nums[mid] == nums[r], because here we can't decide which side to take, only knowing that nums[r] is not equal to target, so move r to the left one step at a time, which may potentially cause the runtime to go linear which may answer the follow up question.