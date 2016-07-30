/*class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            result[i] = (i >> 1) ^ i;
        return result;
    }
};
//^ 为异或操作 exclusive OR */

class Solution {
    public:
    vector<int> grayCode(int n) {
        if(n == 0){
            return vector<int>{0};
        }
        vector<int> pre = grayCode(n - 1);
        
        vector<int> ans(pow(2, n));
        for(int i = 0; i < pre.size(); ++i){
            int tmp = pre[i];
            ans[i] = tmp;
            ans[ans.size() - 1 - i] = tmp + (1 << (n - 1));
        }
        return ans;
    }
};