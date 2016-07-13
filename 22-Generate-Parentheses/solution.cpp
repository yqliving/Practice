

/*Solution: Place n left '(' and n right ')'.
           Cannot place ')' if there are no enough matching '('.
 */
class Solution {
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate (res, n, n, "");
        return res;
    }
    
    void generate(vector<string> & res, int left, int right, string s) {
        if (left == 0 && right == 0) {
            res.push_back(s);
        } 
        if (left > 0) 
            generate(res, left - 1, right, s + "("); // 注意有s
        if (right > left)
            generate(res, left, right - 1, s + ")");
    }
};
