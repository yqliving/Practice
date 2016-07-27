//dynamic programming
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    
    vector<int> dp(nums.size(), 1);
    int maxLength = 1;
    
    for(int i = 1; i<nums.size(); i++) {
        for(int j = i-1; j>=0; j--) {
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        
        maxLength = max(maxLength, dp[i]);
    }
    
    return maxLength;
}
};

//lower_bound
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
};
//return the first element >= nums[i]

//binary search
/*int lengthOfLIS(vector<int>& nums) {
        const int len = nums.size();
        if(len <= 1)  return len;
        int c[len+1],ret = 1;
        for(int i = 0; i <= len; i++){
             c[i] = 0;
        }
        c[1] = nums[0];
        for(int i = 1; i < len; i++){
            int temp = biSearch(c,ret,nums[i]);
            c[temp] = nums[i];
            if(ret < temp)  ret = temp;
        }
        return ret;
    }
    
    int biSearch(int c[], int n, int target){  // to find the right bound
        int left = 1, right = n;
        while(left <= right){
            int mid = (left + right)/2;
            if(c[mid] > target)
                right = mid - 1;
            else if(c[mid] < target)
                left = mid + 1;
            else 
                return mid;
        }
        return left;
    }