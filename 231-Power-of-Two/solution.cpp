class Solution {
public:
    bool isPowerOfTwo(int n) {
        return fmod(log10(n)/log10(2), 1)==0;
        //return n > 0 && (n & (n - 1)) == 0;   // bits method
        //return fmod(log10(n)/log10(2), 1)==0;    //math method
    }
};


// Time ~ O(1), Space ~ O(1) 
// Use property: n & (n - 1) == 0.
// Example: n = 1000, n - 1 = 111, 1000 & 0111 = 0000.

/* class Solution {
public: boolean isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n > 0) {
        if (n != 1 && (n & 1) != 0) return false;   // stop if any bit after 1 is not 0
        n >>= 1;
    }
    return true;
}
}; 
// Time ~ O(N), Space ~ O(1) ,Check each bit after 1 if it's zero.

class Solution {
public boolean isPowerOfTwo(int n) {
    int len = 0;
    int i = n;
    while (i > 0) { // get the bit length
        i >>= 1;
        len++;
    }
    i = 1;
    while (--len > 0) { // create i = 100..00
        i <<= 1;
    }
    return i == n; // compare i and n
}
};


// Time ~ O(2N) where N is the bit length, Space ~ O(1) 
//Create 100...000 and compare with n (need to get the bit length first).