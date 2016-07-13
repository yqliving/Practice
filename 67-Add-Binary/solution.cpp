class Solution {
public:
    
    string addBinary(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    string result;
    while( alen>0 || blen>0) {
        int abit = alen<=0 ? 0 : a[alen-1]-'0';
        int bbit = blen<=0 ? 0 : b[blen-1]-'0';
        int cbit = carry ? 1 : 0;
        result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1) );
        carry = (abit+bbit+cbit>1);
        alen--; blen--;
    }
    if (carry){
        result.insert(result.begin(), '1');
    }
    return result;
    }
};/*
// every time, calculate if there is carry
class Solution{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};