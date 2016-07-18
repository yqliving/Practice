class Solution {
    public:
    bool containDuplicate(vector<int>& nums) {
        vector<int> temp;
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