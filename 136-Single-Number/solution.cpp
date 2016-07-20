class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int num = 0;
    for (int i=0; i<nums.size();i++) 
    {
        num ^= nums[i];
    }
    return num;
        
    }
};

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_set<int> mySet;
    for(int i = 0;i < nums.size();++i){
        if(mySet.find(nums[i]) == mySet.end()) mySet.insert(nums[i]);
        else mySet.erase(nums[i]);
    }
    auto it = mySet.begin();
    return *it;
    }
};

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto num : nums)
            res ^= num;
        return res;
    }
};

/*Bit Manipulation: Time ~ O(N), Space ~ O(1) 
Use XOR:
0 ^ 0 = 1 ^ 1 = 0
0 ^ 1 = 1 ^ 0 = 1