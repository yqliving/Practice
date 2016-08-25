class Solution {
    public:
    bool isPowerOfThree(int n) {
        int i = 0;
        while(3^i < n) {
            i++;
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