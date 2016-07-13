class Solution {
    public:
    string convert (string s, int nRows) {
        if (nRows < 2) return s;
        int n = s.size();
        string res;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j + i < n; j += 2*nRow - 2) {
                res.push_back(s[j+1]);
                if (i == 0 || i == nRows - 1) continue;
                if (j + 2*nRows - 2 - i < n) 
                    res.push_back(s[j + 2*nRows -2 - i]);
            }
        }
        return res;
    }
};
//skip1：主元素之间的距离 = 2 * nRows - 2；
//skip2：主元素和斜线元素之间的距离 = 主元素间距逐次递减 2（除第一行和最后一行外，其他行每个主元素之后都跟一个斜线元素）。