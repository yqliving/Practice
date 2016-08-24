class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabet(26,0);
        for (int i = 0; i < s.size(); i++){
            alphabet[s[i] -'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (alphabet[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
/*class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(char c : s) {
            m[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};