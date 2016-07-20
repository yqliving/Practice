class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.size() !=t.size())
       {
           return false;
       }
       else {
           sort (s.begin(),s.end());
           sort (t.begin(),t.end());
           if (t==s)
           return true;
           else return false;
       }
    }
};