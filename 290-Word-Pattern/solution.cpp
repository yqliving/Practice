calss Solution {
    public:
    bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); i++) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") {
                s2c[vs[i]] = pattern[i];
                c2s[pattern[i]] = vs[i];
                continue;
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
};

    
    /*class Solution {
public:
   bool wordPattern(string pattern, string str) 
{
    istringstream ss(str);
    string word;
    unordered_map<char, string> bmap;
    unordered_map<string, char>rbmap;
    
    for (char c : pattern)
    {
        if (! (getline(ss, word, ' ')))
            return false;
        if ( bmap.emplace(c,word).first->second != word)
            return false;
        if (rbmap.emplace(word,c).first->second != c)
            return false;
    }
    return ! getline(ss, word, ' ');   
}
};