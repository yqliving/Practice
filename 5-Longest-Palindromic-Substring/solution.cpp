
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length(), maxLen = 0, leftMost = 0;
        int i = 0, start = 0, end = 0, len = 0;
        while(i <= n - maxLen/2)     //!!!!!! 条件
        {
            start = end = i;
            while(end <n-1 && s[end+1]==s[end]) end++;
            i = end+1;
            while(start>0 && end<n-1 && s[end+1]==s[start-1]) {
                start --;
                end ++;
            }
            len = end - start + 1;
            if(maxLen < len) {
                leftMost = start;
                maxLen = len;
            }
        }
        return s.substr(leftMost, maxLen);
    }
};
// find the middle vulue of the Palindromic Substring, check if its left = right;

/*class Solution {
public:
    string longestPalindrome(string s) {
  int n = s.length();
  int longestBegin = 0;
  int maxLen = 1;
  bool table[1000][1000] = {false};
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  return s.substr(longestBegin, maxLen);
}
};