class Solution {
public:
    vector<bool> vis;
    vector<int> dis;
    vector<int> pre;
    queue<int> q;
    pair <int, int> last_leaf;
    void bfs(int root, vector<vector<int>> &adj, int previous)
    {
        q.push(root);
        pre[previous] = -1;
        last_leaf = {0, 0};
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;
            if (last_leaf.first < dis[u])
            {
                last_leaf.first = dis[u];
                last_leaf.second = u;
            }
            for (auto x : adj[u])
            {
                if (!vis[x])
                {
                    q.push(x);
                    dis[x] = dis[u] + 1;
                    pre[x] = u;
                }
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vis.assign(n, false);
        dis.assign(n, 0);
        pre.assign(n, -1);
        bfs(0, adj, 0);

        vis.assign(n, false);
        dis.assign(n, 0);
        pre.assign(n, -1);
        bfs(last_leaf.second, adj, last_leaf.second);

        vector<int> ans;
        vector<int> diameter;
        int node = last_leaf.second;
        diameter.push_back(node);
        while (pre[node] != -1)
        {
            node = pre[node];
            diameter.push_back(node);
        }
        if (diameter.size() % 2 == 1)
            ans.push_back(diameter[(diameter.size() - 1) / 2]);
        else
        {
            ans.push_back(diameter[diameter.size() / 2]);
            ans.push_back(diameter[diameter.size() / 2 - 1]);
        }
        return ans;
    }
};