//递归
class Solution {
    public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string s;
        if (digits.size() == 0) return res;
        Combine(keyboard, digits, s, res);
        return res;
    }
    
    void Combine(vector<string>& keyboard, string & digits, string & s, vector<string>& res) {
        if (s.size() == digits.size()) {
            res.push_back(s);
            return;
        }
        string letters = keyboard[digits[s.size()] - '0'];
        for (int i = 0; i < letters.size(); i ++) {
            s.push_back(letters[i]);
            Combine(keyboard, digits, s, res);
            s.pop_back;
        }
    }
};

// iteration
/*
vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}