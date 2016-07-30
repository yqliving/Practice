class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k == 0) return res;

        vector<int> cur;
        recur(n, k, 1, res, cur);

        return ret;
    }

    void recur(int n, int k, int start, vector<vector<int>> &res, vector<int> &cur) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; n - i + 1 >= k; i++) {
            cur.push_back(i);
            recur(n, k - 1, i + 1, res, cur);
            cur.pop_back();
        }
    }
};


/*class Solution {
public:
vector<vector<int>> combine(int n, int k) {
    if (n == 0 || k == 0) {
        return vector<vector<int>>(0);
    }
    int i = 0;
    vector<int> path(k, 0);
    vector<vector<int>> results;

    while (i >= 0) {
        if (i == k) {
            results.push_back(vector<int>(path));
            i--;
        }
        path[i] ++;
        while (i > 0 && path[i] <= path[i - 1] || i == 0 && path[i] <= 0) {
            path[i] ++;
        }
        if (path[i] > n - k + i + 1) {
            path[i] = 0;
            i--;
        } else {
            i++;
        }
    }
    return results;
}
}; */