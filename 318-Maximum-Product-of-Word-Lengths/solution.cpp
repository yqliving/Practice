class Solution {
public:
int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    int result = 0;
    for (int i=0; i<words.size(); ++i) {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');   //相当于a放在最后一位，b放在倒数第二位，c。。。
        for (int j=0; j<i; ++j)
            if (!(mask[i] & mask[j]))
                result = max(result, int(words[i].size() * words[j].size()));
    }
    return result;
}
};


/*class Solution {
public:
    int maxProduct(vector<string>& words) {
    unordered_map<int,int> maxlen;
    for (string word : words) {
        int mask = 0;
        for (char c : word)
            mask |= 1 << (c - 'a');
        maxlen[mask] = max(maxlen[mask], (int) word.size());
    }
    int result = 0;
    for (auto a : maxlen)
        for (auto b : maxlen)
            if (!(a.first & b.first))
                result = max(result, a.second * b.second);
    return result;
}
};
//O(n+N) variation, where N is the total number of characters in all words