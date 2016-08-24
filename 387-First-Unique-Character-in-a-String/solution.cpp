class Solution{
    public:
    int firstUniqChar(string s) {
        if (s.size()==0) return -1;
        vector<int> m(128, 0);
        for (auto c:s)
           m[c]++;
        int i=0;   
        for (;i<s.size();i++){
            if (m[s[i]]==1) break;
        }
        return (i==s.size()) ? -1 : i;
    }
};/*class Solution {
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