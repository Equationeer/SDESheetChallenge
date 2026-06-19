class Solution{
public:
    bool isSafe(int node, int color,vector<vector<int>>& adj,vector<int>& colors) {
        
        for (int neigh : adj[node]) {
            if (colors[neigh] == color)
                return false;
        }
        return true;
    }

    bool solve(int node, int n, int m,vector<vector<int>>& adj,vector<int>& colors) {
        
        if (node == n)
            return true;

        for (int color = 1; color <= m; color++) {
            if (isSafe(node, color, adj, colors)) {
                colors[node] = color;

                if (solve(node + 1, n, m, adj, colors))
                    return true;

                colors[node] = 0; 
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        //your code goes here
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, 0);

        return solve(0, n, m, adj, colors);
    }
};