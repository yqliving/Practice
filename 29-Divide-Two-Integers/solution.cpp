class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
        long long newdividend = labs(dividend);
        long long newdivisor = labs(divisor);
        int ans = 0;
        while (newdividend >= newdivisor) {
            long long tmp = newdivisor;
            int m = 1;
            while (newdividend >= (tmp << 1)) {
                m = m << 1;
                tmp = tmp << 1;
            }
            newdividend -= tmp;
            ans += m;
        }
        return ans * sign;
    }
};
//时间复杂度O(log n), 因为不能除，所以每次都减被除数, 左移记录被除数扩大的倍数

//2. a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))
/*
class Solution {
    public:
        int divide(int dividend, int divisor) {
            // a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))
            if(dividend==0)  return 0;
            if(divisor==0)  return INT_MAX;
            
            double t1=log(fabs(dividend));
            double t2=log(fabs(divisor));
            long long result=double(exp(t1-t2));
            if((dividend<0) ^ (divisor<0))  result=-result;
            if(result>INT_MAX)  result=INT_MAX;
            return result;
        }
    };
