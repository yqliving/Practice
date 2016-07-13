class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        for(int i = 0;i < strs[0].size(); ++i){ //纵向扫描
            for(int j = 1;j < strs.size(); ++j){
                if(strs[j][i] != strs[0][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};

//纵向扫描，从位置0开始， 对每一个位置比较所有字符串，直到遇到一个不匹配
//时间复杂度，O（n1+n2+n3...）
