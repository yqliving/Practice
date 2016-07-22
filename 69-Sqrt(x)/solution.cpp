class Solution {
public:
   int mySqrt(int x) {

        int p = 0, q = x;
        while(p < q)
        {
            // Basically, q = (p+q)/2. Code like below has two purpose: 
            // 1) avoid overflow.
            // 2) handle corner case, such as x = 1, prevent divided-by-zero error for p=x/q.
            q = max(1, p + (q - p) / 2);  
            p = x / q;
        }

        return p > q ?  q: p; // if the loop exits because p > q, return q; otherwise, p is the answer.
    }
};
//不断取中间值逼近