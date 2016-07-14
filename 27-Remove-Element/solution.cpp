//
// Created by Xiaoying Gao on 6/13/16.
//
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[size] = nums[i];
                size ++;
            }
        }
        return size;
    }
};
