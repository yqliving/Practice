class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
        int mx = 0, mx_idx = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (mx < dp[i]) {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
};

/*class Solution {
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