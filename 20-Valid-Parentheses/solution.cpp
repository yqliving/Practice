class Solution {
    public:
    bool isValid(string s) {
    stack<char> temp;
    map<char, char> m = { {']','['},{')','('},{'}','{'} };
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            temp.push(s[i]);
        else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if (temp.empty()||temp.top() != m[s[i]]) return false;
            else temp.pop();
        }
    }
    return temp.empty();
}
};

/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else if(st.empty()) return false;
            else if(ch == ')' && st.top() == '(') st.pop();
            else if(ch == ']' && st.top() == '[') st.pop();
            else if(ch == '}' && st.top() == '{') st.pop();
            else break;
        }
        return st.empty();
    }
};


/*class Solution {
public:
    bool isValid(string s) {
        int top=-1,index=0,length=s.size();
        char* stack=(char*)malloc(sizeof(char)*length);
        while(index<length){
            if(s[index]==')'){
                if(top>=0 && stack[top]=='(')top--;
                else return false;
            }else if(s[index]=='}'){
                if(top>=0 && stack[top]=='{')top--;
                else return false;
            }else if(s[index]==']'){
                if(top>=0 && stack[top]=='[')top--;
                else return false;
            }else stack[++top]=s[index];
            index++;
        }
        return top==-1;
    }
};