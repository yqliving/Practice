class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        
        //int m1[256] = {0}, m2[256] = {0};
        unordered_map<char, int> m1, m2;
        
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};


/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size()== 0)
            return true;
        
        
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        map1.insert(make_pair(s[0], t[0]));
        map2.insert(make_pair(t[0], s[0]));
        
        
        for (int i = 1; i< s.size(); i++){
            if (map1.find(s[i])!=map1.end()){
                if (t[i] != map1.at(s[i])) {
                    return false;
                }
            }
            
            if (map2.find(t[i])!=map2.end()){
                
                if (s[i] != map2.at(t[i])) {
                    return false;
                }
            }
            
            else{
                map1.insert(make_pair(s[i],t[i]));
                map2.insert(make_pair(t[i],s[i]));
            }
            
        }
        return true;
    }
};