
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2)
            return s;

        int leftMost=0, maxLen=0;
        int start, end;
        int i = 0;
        while (i < n - maxLen/2 )
        {
            start = i;
            end = i;
            while(end < n - 1 && s[end + 1]==s[end])
            {
                end ++;
            }

            while(start > 0 && end < n-1 && s[start-1]==s[end+1])
            {
                start--;
                end++;
            }
            int len = end - start + 1;

            if(maxLen < len)
            {
                leftMost = start;
                maxLen = end;
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