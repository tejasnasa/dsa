class Solution {
public:
    void dfs(int v, unordered_map<int, list<int>> &adj, vector<bool> &visited) {
        if (visited[v]) return;
        visited[v] = true;

        for (auto child: adj[v]) {
            dfs(child,adj,visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        vector<bool> visited(n,false);

        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                dfs(v,adj,visited);
                res++;
            }
        }

        return res;
    }
};
