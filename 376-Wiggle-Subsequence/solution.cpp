/*思路: 可以看到如果以动态规划的方式来解决是比较直观的, 其状态转移方程也比较容易得出: 

if(nums[i]-nums[j])*(nums[j]-nums[j-1] <0) dp[i] = max(dp[i], dp[j]+1);

else dp[i] = max(dp[i], dp[j]);

这种方法的时间复杂度很明显也是O(n^2), 空间复杂度为O(n).

而为了能够在O(n)时间内解决可以考虑使用贪心法. 举个栗子: [1,17,5,10,13,15,10,5,16,8], 可以看到前两个[1, 17]确定了一个递增的序列, 而[17, 5]构成了一个递减序列, 所以到目前位置都正常. 到了[10, 13, 15]这里就有问题了, 他们和之前的5构成了一个递增序列, 而出于贪心的考虑, 必然是选择15是最优解, 因为这样给后面序列最大的选择空间. 对于接下来的[10, 5]都与之前的15构成递减区间, 同样道理我们选择5来构造这个序列. 所以一个基于贪心的算法大概就是这样了. 其时间复杂度为(n), 空间复杂度为O(1).

两种代码如下:
动归:*/

class Solution {  
public:  
    int wiggleMaxLength(vector<int>& nums) {  
        if(nums.size() < 2) return nums.size();  
        int len = nums.size();  
        vector<int> dp(len, 0);  
        dp[0] = 1, dp[1]= dp[0] + (nums[1]!=nums[0]);  
        for(int i = 2; i < len; i++)  
        {  
            for(int j = 1; j < i; j++)  
            {  
                dp[i] = max(dp[i], dp[j] + ((nums[i]-nums[j])*(nums[j]-nums[j-1])<0));  
            }  
        }  
        return dp[len-1];  
    }  
};  

//greedy  O(n)
/*
class Solution {  
public:  
    int wiggleMaxLength(vector<int>& nums) {  
        if(nums.size() < 2) return nums.size();  
        int len = nums.size(), ans = len, flag = 0;  
        for(int i = 1; i < len; i++)  
        {  
            if(nums[i]-nums[i-1] == 0) ans--;  
            else if(nums[i]-nums[i-1]>0) flag==1?ans--:flag=1;  
            else if(nums[i]-nums[i-1]<0) flag==-1?ans--:flag=-1;  
        }  
        return ans;  
    }  
};  
