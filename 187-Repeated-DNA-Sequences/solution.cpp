/*class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    char  hashMap[1048576] = {0};
    vector<string> ans;
    int len = s.size(),hashNum = 0;
    if (len < 11) return ans;
    for (int i = 0;i < 9;++i)
        hashNum = hashNum << 2 | (s[i] - 'A' + 1) % 5;
    for (int i = 9;i < len;++i)
        if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
            ans.push_back(s.substr(i-9,10));
    return ans;
}
}; */
 
 /*class Solution {
public:
int str2int(string s) {
    int str=0;
    for (int i = 0; i < s.size(); ++i)
        str = (str<<3) +(s[i]&7);
    return str;
}
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<int,int> coll;
    for (int i = 0; i+10 <= s.size(); ++i)
        if (coll[str2int(s.substr(i,10))]++ == 1)
            res.push_back(s.substr(i,10));
    return res;
}
};

*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> map;
    hash<string> hash_fn;
    vector<string> v;
    
    for(int i = 0 ; i + 9 < s.size(); i++)
    {
       string t = s.substr(i, 10);
       int h = hash_fn(t);
       
       if(map.find(h) == map.end())
       {
          map[h] = 1;
       }
       else
       {
           if (map[h] == 1)
           {
               v.insert (v.end(), t);
           }
           
            map[h]++;
       }
    }
    
    return v;
}
};