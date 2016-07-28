/*Idea is simple. Powers of four are 1, 4, 16.. or in binary, 0x0001, 0x0100, etc. Only one bit is ever set, and it's always an odd bit. So simply check for that...

This does not use any loops or recursion, is O(1) time and O(1) space. */

class Solution {
public:
    bool isPowerOfFour(int num) {
        // first check only one bit is set:
        if ((num & (num -1)) != 0) return false;  //(n & (n - 1)) == 0; 代表是power of 2
        // next check if it's a bit in pos 1, 3, 5 ... 31
        if (num & 0x55555555) return true;  
        //0x55555555 十六进制数，是01010101010101010101010101010101
        return false;
    }
};