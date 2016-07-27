class Solution {
public:
    int climbStairs(int n) {
        vector<int> a(50);
        a[0]=0;a[1]=1;
        for(int i=2;i<=n+1;i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n+1];
    }
};
//dynamic programming
//The answer is fibonacci sequence: F(n) = F(n-1) + F(n-2). The explanation is that you could reach the nth step either from the n-1th step or n-2th step
