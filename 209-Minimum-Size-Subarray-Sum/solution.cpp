class Solution {
    public:
    int minSunArrayLen(int s, vector<int>& nums) {
        int len = INT_MAX;
        int pre = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                len = min(len, i - pre + 1);
                sum -= nums[pre];
                pre ++;
            }
        }
        return len > nums.size() ? 0 : len;
    }
};

//这个是找最短的子序列

//Two Pointers: Time ~ O(N), Space ~ O(1) 
//前指针向前扫，当 sum >= s 时向前移动后指针 prev (shrink the subarray)，只到 sum < s 为止，并记录最短的 subarray 的长度。
// [2,3,1,2,4,3] first time [2,3,1,2] - [2]
//               second time [3,1,2,4] - [3] = [1,2,4]
//               third time [1,2,4, 3] .....


/*class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int length = nums.size();
        int start, end, crtSum, minLength;
        start = end = crtSum = 0;
        minLength = length + 1;

        while (end < length) {

            while (crtSum < s && end < length) {
                crtSum += nums[end++];
            }

            while (crtSum >= s && start < length) {
                if (end - start < minLength) {
                    minLength = end - start;
                }
                crtSum -= nums[start++];
            }
        }

        return minLength > length ? 0 : minLength;
    }
};