class Solution {
    public:
    bool isPowerOfThree(int n) {
        for (int i = 0; 3^i < n; i++) {
            if (n > 3^i) break;
        }
        return (3^i == n) ;
        
    }
};
/*class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
        
    }
};
//fmod 取余