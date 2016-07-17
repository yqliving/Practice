class Solution {
    public: 
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] ++;
                return digits;
            }
            else {
                if (i == 0) {
                    vector<int> dig(n + 1);
                    dig[0] = 1;
                    return dig;
                } else {
                    digits[i] = 0;
                }
            }
        }
        return digits;
    }
};


// 数位从高到低从左到右存放在 array 中，然后在末尾加一。
//主要解决进位问题，尤其是如果最高位的进位，结果一定为 100...00，重新生成一个 int[N + 1] 返回。
//注意：当没有进位 (carry) 时即可停止。  
