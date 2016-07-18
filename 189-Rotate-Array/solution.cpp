class Solution {
    public: 
    void rotate(vector<int> & nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
    }
    
};
