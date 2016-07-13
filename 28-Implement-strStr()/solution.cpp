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