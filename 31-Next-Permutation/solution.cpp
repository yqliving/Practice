/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = nums.size() - 1;
        while (p > 0 && nums[p] <= nums[p-1]) {
            p --;
        }
        if (p == 0) {
            reverse(nums, 0, nums.size() - 1);
            return;
        }
        int q = nums.size() - 1;
        while (nums[q] <= nums[p-1]) {
            q --;
        }
        int temp = nums[p-1]; 
        nums[p-1] = nums[q];
        nums[q] = temp;
        reverse(nums, p, nums.size() - 1);
        
    }
    
    private:
    void reverse (vector<int>&a, int from, int to) {
        for (; from < to; from ++, to --) {
            int temp = a[from];
            a[from] = a[to];
            a[to] = temp;
        }
    }
};
*/
// the first 12 ms, the second 16ms
class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size() - 1, i;
        for (i = len; i >= 1; i --) {
            if (nums[i] > nums[i - 1]) break;
        }
        if (i == 0) {
            reverse (nums.begin(), nums,end());
            return;
        }
        int left= i - 1;
        int right = nums.size() - 1;
        while (nums[left] >= nums[right]) right--;
        swap(nums[left], num[right]);
        
        reserse(nums.begin() + left + 1, nums.end());
    }
};
/*
class Solution {
public:
void nextPermutation(vector<int>& nums) {

    int length=nums.size()-1, i;
    for(i=length;i>=1;i--) {
    if(nums[i]>nums[i-1])break;
    }
    if(i==0){
        reverse(nums.begin(), nums.end());
        return;
    }
    int left = i-1;
    int right = nums.size() - 1;

    while (nums[left] >= nums[right] )right--;
        swap(nums[left], nums[right]);

    reverse(nums.begin() + left+1, nums.end());

}
};