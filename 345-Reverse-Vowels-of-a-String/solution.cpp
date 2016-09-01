class Solution {
public:
    string reverseVowels(string s) {
        auto left = s.begin(), right = s.end() - 1;
        string vowels = "aeiouAEIOU";
        while(left < right) {
            if((vowels.find(*left) == string::npos)) left++;
            if((vowels.find(*right) == string::npos)) right--;
            if (vowels.find(*left) != string::npos && vowels.find(*right) != string::npos) {
                swap(*left, *right);
                left++;
                right--;
            }
        }
        return s;
    }
};
//当 str.find("哦")==string::npos时则说明字符串str中不存在“哦”这个字符