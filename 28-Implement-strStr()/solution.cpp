class Solution {
    public:
    int strStr(string haystack, string needle) {
        int lenH = haystack.size();
        int lenN = needle.size();
        for (int i = 0; i <= lenH - lenN; i++) {
            int j = 0;
            for (j = 0; j < lenN; j++) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == lenN) return i;
        }
        return -1;
    }
};
// 两个循环 大循环就是遍历长字符串, 然后在长字符串的每个起始位都开始小循环比对字符