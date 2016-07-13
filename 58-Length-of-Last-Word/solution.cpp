class Solution {
public:
    int lengthOfLastWord(string s) {
    int len = 0, last = s.length() - 1;
    while (last >= 0 && s[last] == ' ')  last--;  //先跳过尾部的空格，遇到第一个字符开始记长度
    while (last >= 0 && s[last] != ' ')  {
        last--;
        len++;
    }
    return len;
        
    }
};