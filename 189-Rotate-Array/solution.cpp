/*class Solution {
    public: 
    void rotate(vector<int> & nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
    }
    
};*/

/*======
前半部分反转，后半部分反转，再整体反转。*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, nums+(n-k));
        reverse(nums+(n-k), nums+n);
        reverse(nums, nums+n);
    }
};
