class Solution {
public:
    void reverseWords(string &s) {
    istringstream is(s);
    string tmp;
    is >> s;
    while(is >> tmp) s = tmp + " " + s;
    if(s[0] == ' ') s = "";
}
};
// istringstream类用于执行C++风格的串流的输入操作。ostringstream类用于执行C风格的串流的输出操作。


/*class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int pos = 0;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == ' '){
                if (i > pos )
                    result = s.substr(pos,i-pos)+ " " + result ;
                pos = i + 1;
            }
            else if (i == s.size()-1)
                result = s.substr(pos,s.size()-pos)+" "+result;
        }
        s = result.substr(0,result.size()-1) ;
    }
};