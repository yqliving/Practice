//DFS
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
        void dfs(string u, vector<string> &ans, int & dep, int & tot){
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

/*class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}
};
/*
Explanation

First keep going forward until you get stuck. That's a good main path already. Remaining tickets form cycles which are found on the way back and get merged into that main path. By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy - the end part of the path has already been written, the start part of the path hasn't been written yet, so just write down the cycle now and then keep backwards-writing the path.

Example:

enter image description here

From JFK we first visit JFK -> A -> C -> D -> A. There we're stuck, so we write down A as the end of the route and retreat back to D. There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again, retreat and write down the airports while doing so: Write down D before B, then JFK before D, etc. When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A. Then we retreat further along the original path, prepending C, A and finally JFK to the route, ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.