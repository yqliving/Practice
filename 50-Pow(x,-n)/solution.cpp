
class Solution {
public:
    double myPow(double x, int n) {
        double tmp = x, res = 1.0;
        int flag = 0;
        long r= n ;   //long !!!!!!!!!
        if(r < 0){
            flag =1;
            r = -r;
        }
        while(r > 0){
            if(r%2 == 1){
                res*=tmp;
            }
            tmp *= tmp;
            r = r/2;
        }
        if(flag == 1)return 1.0/res;
        return res;
    }
};
//Recursion: Time ~ O(logN), Space ~ O(1) 
//if n is even, pow(x, n) = pow(x, n/2) * pow(x, n/2);
//if n is odd, pow(x, n) = pow(x, n/2) * pow(x, n/2) * x.

/*class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double last = n > 0 ? x : 1/x;
        long r = abs((long)n);
        while (r > 0) {
            if (r & 1) result *= last;
            r >>= 1;
            last *= last;
        }
        return result;
    }
};