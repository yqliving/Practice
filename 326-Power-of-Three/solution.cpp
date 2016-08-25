class Solution {
    public:
    bool isPowerOfThree(int n) {
        if (n==0) return false;
        int i=0;
        for(; 3^i < n; i++){
            if (n == 3^(i+1))) return true;
            if(3^(i+1) > n) break;
        }
        return false;
        
    }
};
/*class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
        
    }
};
//fmod 取余