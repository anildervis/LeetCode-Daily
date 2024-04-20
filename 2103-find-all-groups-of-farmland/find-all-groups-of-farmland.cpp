class Solution {
public:
    vector<bool> vis = vector<bool> (90600);
    array<int, 2> dx = {1, 0};
    array<int, 2> dy = {0, 1};
    queue<pair<int, int>> q;
    vector<vector<int>> ans;
    void find_island(vector<vector<int>>& grid, int i, int j)
    {
        if (vis[i * 301 + j] or grid[i][j] == 0)
            return ;
        if ((i == grid.size() - 1 or grid[i + 1][j] == 0) and (j == grid[0].size() - 1 or grid[i][j + 1] == 0))
        {
            ans.push_back({q.front().first, q.front().second, i, j});
            q.pop();
        }
        vis[i * 301 + j] = 1;
        for (int k = 0; k < 2; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 and ni < grid.size() and nj >= 0 and nj < grid[0].size() and !vis[ni * 301 + nj] and grid[ni][nj] == 1)
                find_island(grid, ni, nj);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (vis[i * 301 + j])
                    continue;
                if (land[i][j] == 1)
                {
                    q.push({i, j});
                    find_island(land, i, j);
                }
                vis[i * 301 + j] = 1;
            }
        }
        return ans;
    }
};