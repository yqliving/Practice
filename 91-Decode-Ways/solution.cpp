
 
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size(), *ans = new int[len]();
        for(int i=0; i<len; i++){
            // Check one character
            if('1'<=s[i] && s[i]<='9')              // 1 ~ 9
                if(i==0) 
                    ans[i] = 1;
                else 
                    ans[i] = ans[i-1];
            // Check two characters
            if((s[i-1]=='1' && ('0' <= s[i] && s[i] <= '9')) ||     // 10 ~ 19
               (s[i-1]=='2' && ('0' <= s[i] && s[i] <= '6'))){      // 20 ~ 26
                if(i>=2) 
                    ans[i] += ans[i-2];
                else 
                    ans[i]++;
            }
        }
        return ans[len-1];
    }
};

/*每次对于当前的字符判断是否属于1-9（0肯定不行，因为0不在1-26中），如果属于，那么当前的字符可以被decode，并且和f[n-1]组合，f[n] += f[n-1]
然后对于当前字符和前一个字符组成的字符串判断是否属于10-26，如果属于，那么这两个字符可以被decode，并且和f[n-2]组合，f[n] += f[n-2]
*/