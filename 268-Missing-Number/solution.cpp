class Solution
{public:
    int missingNumber(vector<int>& nums){
    int res=0;
    for (int i=0;i<nums.size();i++){
        res^=nums[i]^i;
    }
    res^=nums.size();
    return res;
}
};


/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualSum = 0;
        for (int num = 0; num <= nums.size(); ++num) {
            actualSum += num;
        }
        int currentSum = 0;
        for (auto num : nums) {
            currentSum += num;
        }

        return actualSum - currentSum;
    }
  };
  
/* find only one missing in this array, so we can use sum
sum([0,1,3]) = 4

sum([0,1,2,3]) = 6

6 - 4 = 2