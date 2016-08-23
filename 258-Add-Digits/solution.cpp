class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
        int curRes = 0;
        int cur = num;
        while (cur > 0) {
            curRes += cur % 10;
            cur /= 10;
        }
        num = curRes;
    }
    return num;
    }
};

// two loop  1. if the sum > 9.   find the single number at unit position 