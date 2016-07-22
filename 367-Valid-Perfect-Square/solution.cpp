class Solution {
public:
bool isPerfectSquare(int num) {
    int l = 0, r = num;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
        if(mid * mid < num)
            l = mid + 1;
        else if(mid * mid > num)
            r = mid - 1;
        else
            return true;
    }
    
    return false;
}
};

/*
//based on Newton's method
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = 1;
        int temp = 0;
        
        while (temp != x) {
            temp = x;
            x = round((x + round(num / x)) / 2);
        }

        return x * x == num;
    }
};