class Solution {
public:
    vector<bool> vis = vector<bool> (90600);
    array<int, 4> dx = {1, -1, 0, 0};
    array<int, 4> dy = {0, 0, 1, -1};
    void find_island(vector<vector<char>>& grid, int i, int j)
    {
        vis[i * 301 + j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 and ni < grid.size() and nj >= 0 and nj < grid[0].size() and !vis[ni * 301 + nj] and grid[ni][nj] == '1')
                find_island(grid, ni, nj);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (vis[i * 301 + j])
                    continue;
                if (grid[i][j] == '1')
                {
                    ans++;
                    find_island(grid, i, j);
                }
                vis[i * 301 + j] = 1;
            }
        }
        return ans;
    }
};