//I think all previous C++ solutions read all words into a vector at the start. Here I read them on the fly.
class Solution {
public:
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream ss(str);
    int i = 0, n = pattern.size();
    for (string word; ss >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
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