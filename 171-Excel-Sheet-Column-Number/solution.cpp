class Solution {
public:
    int titleToNumber(string s) {
    int num = 0;
    for (char m : s) {
        num = num * 26 + (int)(m - 'A' + 1);
    }
    return num;
    }
};
