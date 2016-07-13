class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0, N = s.size();
        for (int i = 0; i < N; ++i)
        {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};

//Time ~ O(N), Space ~ O(1) 
//罗马数字要求避免三个以上相同字符连续出现，故加入了减法规则，即用 IV 表示 4，IX 表示 9 等。
//从阿拉伯数字转罗马数字比较简单，只要将各种罗马数字的组合保存，从大的数字减起，每次减完后再查下一个数字。