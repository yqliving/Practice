class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            int i=0, reach=0;
            for(; i<n && i<=reach; i++)
                reach=max(reach, i+nums[i]);
            return reach+1>=n;
        }
    };
 // 记录每一步最远能到达的位置
 
    /*
    class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        int max = nums[0];
        for(int pos = 1; pos <= end; pos++){
            if(pos > max)
                return false;
            if(pos + nums[pos] > max)
                max = pos + nums[pos];
            if(max >= end)
                return true;
        }
        return true;
    }
};