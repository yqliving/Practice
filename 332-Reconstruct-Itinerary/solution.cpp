//DFS
/*这道题给我们一堆飞机票，让我们建立一个行程单，如果有多种方法，取其中字母顺序小的那种方法。这道题的本质是有向图的遍历问题，那么LeetCode关于有向图的题只有两道Course Schedule和Course Schedule II，而那两道是关于有向图的顶点的遍历的，而本题是关于有向图的边的遍历。每张机票都是有向图的一条边，我们需要找出一条经过所有边的路径，那么DFS不是我们的不二选择。先来看递归的结果，我们首先把图建立起来，通过邻接链表来建立。由于题目要求解法按字母顺序小的，那么我们考虑用multiset，可以自动排序。等我们图建立好了以后，从节点JFK开始遍历，只要当前节点映射的multiset里有节点，我们取出这个节点，将其在multiset里删掉，然后继续递归遍历这个节点，由于题目中限定了一定会有解，那么等图中所有的multiset中都没有节点的时候，我们把当前节点存入结果中，然后再一层层回溯回去，将当前节点都存入结果，那么最后我们结果中存的顺序和我们需要的相反的，我们最后再翻转一下即可，参见代码如下：*/
class Solution {
    public:
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            vector<string> ans;
            int n = tickets.size();
            for(int i = 0; i < n; ++ i){
                g[tickets[i].first].insert(tickets[i].second);
            }
            dfs("JFK", ans, 1, n);
       //     puts(" -- ");
            reverse(ans.begin(), ans.end());
            return ans;
        }
    private:
        void dfs(string u, vector<string> &ans, int dep, int tot){
            while(g[u].size()){
                string v = *g[u].begin();
                g[u].erase(g[u].begin());
                dfs(v, ans, dep + 1, tot);
            }
            ans.push_back(u);
        }
    private:
    unordered_map<string, multiset<string> > g;
    //unordered_map<string, set<string>::iterator> vis;
    };

/*下面我们来看迭代的解法，需要借助栈来实现，来实现回溯功能。比如对下面这个例子：

tickets = [["JFK", "KUL"], ["JFK", "NRT"], ["NRT", "JFK"]]

那么建立的图如下：

JFK -> KUL, NRT

NRT -> JFK

由于multiset是按顺序存的，所有KUL会在NRT之前，那么我们起始从JFK开始遍历，先到KUL，但是KUL没有下家了，这时候图中的边并没有遍历完，此时我们需要将KUL存入栈中，然后继续往下遍历，最后再把栈里的节点存回结果即可，参见代码如下：*/

/*
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        stack<string> d;
        unordered_map<string, multiset<string> > m;
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        string cur = "JFK";
        for (int i = 0; i < tickets.size(); ++i) {
            while (m.find(cur) == m.end() || m[cur].empty()) {
                d.push(cur);
                cur = res.back();
                res.pop_back();
            }
            res.push_back(cur);
            string t = cur;
            cur = *m[cur].begin();
            m[t].erase(m[t].begin());
        }
        res.push_back(cur);
        while (!d.empty()) {
            res.push_back(d.top());
            d.pop();
        }
        return res;
    }
};

/*

Explanation

First keep going forward until you get stuck. That's a good main path already. Remaining tickets form cycles which are found on the way back and get merged into that main path. By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy - the end part of the path has already been written, the start part of the path hasn't been written yet, so just write down the cycle now and then keep backwards-writing the path.

Example:

enter image description here

From JFK we first visit JFK -> A -> C -> D -> A. There we're stuck, so we write down A as the end of the route and retreat back to D. There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again, retreat and write down the airports while doing so: Write down D before B, then JFK before D, etc. When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A. Then we retreat further along the original path, prepending C, A and finally JFK to the route, ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.