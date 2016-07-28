
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            ++i;        
        }
        return m<<i;
    }
};
//


/*
class Solution {
public:
int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}
};