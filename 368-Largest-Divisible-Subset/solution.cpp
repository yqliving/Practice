class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        if (N == 0 || N == 1)
            return nums;
        //pair {a, b} means max length ending at current index is a and the previous index is b
        vector<pair<int, int>> dp(N, {1, -1}); 
        pair <int, int> max_ending = {0, -1};
        sort(nums.begin(), nums.end());
        for (int i = 1; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) { //record max length ending at i and the previous index j
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    }
                }
            }
            if(dp[i].first > max_ending.first) { //keep the last element in the final results
                max_ending.first = dp[i].first;
                max_ending.second = i;
            }
        }
        
        vector<int> res;
        while (max_ending.second != -1) { //backtrack from the last element in the results
            res.push_back(nums[max_ending.second]);
            max_ending = dp[max_ending.second];
        }
        return res;
    }
};