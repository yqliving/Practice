
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (log10(n)/log10(3)) % 1 ==0;
        
    }
};
//fmod 取余