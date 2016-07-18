class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return true;
        vector<int> temp;
        //temp[0] = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (count(temp.begin(), temp.end(), nums[i])) return true;
            temp[i] = nums[i];
        }
        return false;
    } 
};
/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) return true;
            mp[nums[i]] = i;
            
        }
        return false;
        
    }
};