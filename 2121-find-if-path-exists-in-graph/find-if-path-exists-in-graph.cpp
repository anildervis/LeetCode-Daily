class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;
        queue<int> q;
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        q.push(source);
        while (!q.empty())
        {
            if (vis[destination])
                break;
            int node = q.front();
            q.pop();
            for (auto v : adj[node])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return vis[destination] == true;
    }
};