
class Solution {
public:
    int removeDuplicates(vector<int>& nums ) {
        int len=nums.size(), i=0, j=0;
        if (len==0) return 0;
        for (i=0;i<len;i++){
            if (i==0 || nums[i]!=nums[i-1]) {
                nums[j]=nums[i];
                j++;
            } ; 
        } 
        return j;
        
    }
};