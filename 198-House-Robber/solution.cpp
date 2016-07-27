class Solution {
public:
    int rob(vector<int>& num) {
    int n = num.size();
    if (n == 0) return 0;
    vector<int> d(n,0);   ////*******
    for (int i = 0; i < n; i++) {
        if      (i == 0)    d[i] = num[i];
        else if (i == 1)    d[i] = max(d[i - 1], num[i]);
        else                d[i] = max(d[i - 1], d[i - 2] + num[i]);
    }
    return d[n-1];
        
    }
};
//dynamic programming
//d(i) = max{d(i - 1), d(i - 2) + s[i]};
//Time ~ O(N), Space ~ O(N) 