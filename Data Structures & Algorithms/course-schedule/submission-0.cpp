class Solution {
public:
    bool dfs(int v, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<bool> &visitPath) {
        if (visitPath[v]) return true;
        if (visited[v]) return false;
        
        visited[v] = true;
        visitPath[v] = true;

        for (auto child: adj[v]) {
            if (dfs(child,adj,visited,visitPath)) return true;
        }

        visitPath[v] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> visitPath(numCourses, false);
        unordered_map<int, list<int>> adj(numCourses);

        for (auto e: prerequisites) {
            adj[e[0]].push_back(e[1]);
        }

        for (int v = 0; v < numCourses; v++) {
            if (!visited[v]) {
                if (dfs(v,adj,visited,visitPath)) return false;
            }
        }

        return true;
    }
};
