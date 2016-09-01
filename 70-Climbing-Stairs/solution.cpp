class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2){return n;}
        vector<int> a(50);
        a[0] = 1, a[1] = 2;
        for(int i=2;i<n;i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n-1];
    }
};
//dynamic programming
//The answer is fibonacci sequence: F(n) = F(n-1) + F(n-2). The explanation is that you could reach the nth step either from the n-1th step or n-2th step
