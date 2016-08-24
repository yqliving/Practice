class Solution{
    public:
    int firstUniqChar(string s) {
        vector<int> counts;
        for (auto m : s) {
            counts[m - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if(counts[s[i] - 'a']==1) return i;
        }
        return -1;
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