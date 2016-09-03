class Solution {
public:
    int reverse(int x) {
        int flag=x>0?1:-1,res=0;
        x=x>0?x:-x;
        while(x>0){
            if(res*10.0+x%10 > INT_MAX)return 0;
            res = res*10+x%10;
            x/=10;
        }
        
        return res*flag;
    }
};