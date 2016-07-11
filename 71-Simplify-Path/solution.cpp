class Solution {
    public:
    string simplifyPath (string path) {
        vector<string> simplify;
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            else if (temp == ".." && simplify.empty()) {
                simplify.pop_back();
            } else if (temp != "..") {
                simplify.push_back();
            }
        }
        string ans = "";
        for (string i : simplify) {
            ans += "/" + i;
        }
        if (ans == "") ans = "/";
        return ans;
    }
};
/*stringstream 是 C++ 提供的另一个字串型的串流(stream)物件，和之前学过的 iostream、fstream 有类似的操作方式。要使用 stringstream， 必須先加入這一行：
#include <sstream>
stringstream 主要是用在將一個字串分割，可以先用 clear( )以及 str( ) 將指定字串設定成一开始的內容;

getline（istream &in, string &s）从输入流中读入字符，存到string s变量*/


/*class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        vector<string> nodes;
        string result;
        split(path, '/', nodes);
        for(auto node : nodes) {
            //empty or only '.' path no change
            if(node == "" || node == ".")  continue;
            //go back to the upper directory
            if(node == ".." && !st.empty())  st.pop_back();
            //push back the current directory
            else if(node != "..")  st.push_back(node);
        }
        for(auto it : st) result += "/" + it;
        return result.empty() ? "/" : result;
    }

    void split(string s, char delim, vector<string>& nodes) {
        string temp;
        stringstream ss(s);
        while(getline(ss, temp, delim)) {
            nodes.push_back(temp);
        }
    }
};