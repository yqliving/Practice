class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int p1 = 0, p2 = 1;
        int maxLen = p2 - p1;
        for (; p2 < s.size(); p2++) {
            for (int i = p1; i < p2; i++) {
                if (s[i] == s[p2]) {
                    p1 = i + 1;
                    break;
                }
            }
            maxLen = max(maxLen, p2 - p1 + 1);
        }
        return maxLen;
    }
};

//constant space,two indexes


//2. hashtable
/*If position of last found char same as s[r] is beyond l, which means the window will have two same chars s[r] now, so we need to move forward l to shrink the window. Otherwise, l stays the same. That's all what	says. Your feedback or any thought is welcome. I really learnt a lot from all you genius.

Example 1 "tmmzuxt"

s[l] is the 2nd "m", s[r] is the last "t", and the last found t is not in the current window, no need to update l.

Example 2 "mmzuxtabt"

s[l] is the 2nd m, s[r] is the last "t", and the last found "t" is in the current window, so move l forward to "a". */
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, len=0;
        unordered_map<char, int> window;
        while(r<s.size()){
            if(window.find(s[r])!=window.end())
                l=max(l,window[s[r]]+1);      //see explain      
            window[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};