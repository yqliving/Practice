class Solution { 
public:
string largestNumber(vector<int> &num) {
    string result;
    vector<string> str;
    for (auto n : num) {
        str.push_back(to_string(n));
    }
    sort(str.begin(), str.end(), compareNum);
    for (auto s: str) {
        result += s;
    }
    
    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
    return result.substr(pos);
} 
private:
static bool compareNum(string a, string b) {
    return a + b > b + a;
}
};




/*class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans;
        for(int i=0; i<num.size(); i++){
            ans += to_string(num[i]);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};
