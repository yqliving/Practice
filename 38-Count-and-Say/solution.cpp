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