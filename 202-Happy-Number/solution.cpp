/*class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
		return true;
        } else if (n == 4) {
		return false;
        } else {
            int sum = 0;
            while (n){
                sum += pow(n % 10, 2);
                n /= 10;
            }
            return isHappy(sum);
        }
    }
}; */

class Solution {
public:
    bool isHappy(int n) {

    if (n==1) return true;
    unordered_map<int, bool> tmp;

    while (n!=1) {
        if (tmp[n] == 0) {
            temp[n]++;
        }else {
            return false;
        }
        n = squares(n);
    }
    return true;
}

int squares(int n) {
    int result = 0;
    int sq = 0;
    for (; n>0; n/=10) {
        sq = n%10;
        result += (sq * sq);
    }
    return result;
}
};