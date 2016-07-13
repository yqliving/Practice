class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), i;
        if(n<2)
            return s;

        int leftMost=0, rightMost=0;
        i = 0;
        int start, end;
        while(i<n)
        {
            start = i;
            end = i;
            i++;
            while(i<n && s[i]==s[start])
            {
                i++;
            }
            end = i-1;

            while(start-1>=0 && end+1<n && s[start-1]==s[end+1])
            {
                start--;
                end++;
            }

            if(rightMost-leftMost <= end-start)
            {
                leftMost = start;
                rightMost = end;
            }
        }

        return s.substr(leftMost, rightMost-leftMost+1);
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