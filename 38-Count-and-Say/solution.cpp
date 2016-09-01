class Solution {
    public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            stringstream ss;
            int j = 0;
            int N = res.size();
            while (j < N) {
                int count = 0;
                while ((j + count) < N && res[j + count] == res[j]) {
                    count ++;
                }
                ss << count << res[j];
                j = j + count;
            }
            ss >> res;
        } return res;
    }
};
//用count计数

/*string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}