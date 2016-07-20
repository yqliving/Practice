class Solution {
public:
    bool isHappy(int n) {

    if (n==1) return true;

    unordered_map<int, bool> m;
    m[n]=true;

    while (n!=1) {
        n = squares(n);
        //cout << n << endl;
        if (m.find(n) != m.end()){
            return false;
        }
        m[n] = true;
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