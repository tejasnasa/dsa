class Solution {
public:
    void dfs(int vertex, vector<vector<int>> &graph, vector<int> &visited) {
        if (visited[vertex]) return;
        visited[vertex] = true;

        for (int child: graph[vertex]) {
            dfs(child,graph,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i,graph,visited);
                res++;
            }
        }

        return res;
    }
};