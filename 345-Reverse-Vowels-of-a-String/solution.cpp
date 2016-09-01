class Solution {
public:
    string reverseVowels(string s) {
        auto p1 = s.begin(), p2 = s.end() - 1;
        string vowels = "aeiouAEIOU";
        while(p1 < p2) {
            while((vowels.find(*p1) == string::npos)) p1++;
            while((vowels.find(*p2) == string::npos)) p2--;
            if(p1 < p2) swap(*p1, *p2);
            p1++;
            p2--;
        }
        return s;
    }
};
//当 str.find("哦")==string::npos时则说明字符串str中不存在“哦”这个字符