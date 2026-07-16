class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        vector<int> ans;

        dfs(0, adj, vis, ans);

        return ans;
    }

    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        vector<int> ans;
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
};