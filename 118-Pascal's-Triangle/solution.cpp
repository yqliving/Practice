class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res(numRows);      ///initial 2D  如果是一维的，可以直接res（num， 1）
        if (numRows < 1)
        return res;
        
        res[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            res[i].push_back(1);
            for (int j = 1; j < i; j++) {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
        