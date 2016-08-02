class Solution {
public:
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > g(numCourses);
		vector<int> in_degree(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); i++){
			g[prerequisites[i].second].push_back(prerequisites[i].first);
			in_degree[prerequisites[i].first]++;
		}
		queue<int> q;
		int cnt = 0;
		for (int i = 0; i < numCourses; i++) if (in_degree[i] == 0) q.push(i);
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			for (auto it = g[cur].begin(); it != g[cur].end(); it++)
				if (--in_degree[*it] == 0) q.push(*it);
		}
 
		for (int i = 0; i < numCourses; i++) if (in_degree[i] != 0) return false;
		return true;
	}
};
	
	
/*class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
};