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
};*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size>1){
            sort(nums.begin(), nums.end());
            for(int i=0; i<size; ++i)
                if(nums[i] == nums[i+1] && i+1 != size)
                    return true;
        }
        return false;
    }
};
/*