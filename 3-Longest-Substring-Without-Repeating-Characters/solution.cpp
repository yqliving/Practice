class Solution {
    public:
    int lengthOfLongestSibstring(string s) {
        if (s.empty()) return 0;
        
        int p1 = 0, p2 = 1;
        int maxLen = p2 - p1;
        for (; p2 < s.size(); p2++) {
            for (int i = 0; i < p2; i++) {
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


//2.
//one pass, two pointers with map table

/*int str_len = s.length();
    int l = 0;
    int len = 0;
    int max_len = 0;
    int char_indexes[128]; // vector adds 4 ms. to be faster using array
    memset(char_indexes, -1, sizeof(char_indexes)); 

    char c = '\0';
    int prev_indx_of_cur_char = 0;
    for (int r = 0; r < str_len; ++r)
    {
        c = s[r];
        prev_indx_of_cur_char = char_indexes[c];
        if (prev_indx_of_cur_char >= l )
        {
            l = prev_indx_of_cur_char + 1;
            len = r - l + 1;
        }
        else
        {
            ++len;
        }
        char_indexes[c] = r;
        max_len = max(len, max_len);
    }

    return max_len;