class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        unordered_map<int, bool> vis;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                    continue;
                vis[i * 101 + j] = 1;
                if (vis[(i - 1) * 101 + j] == 0 and vis[i * 101 + j - 1] == 0)
                    ans += 4;
                else if (vis[(i - 1) * 101 + j] == 0 or vis[i * 101 + j - 1] == 0)
                    ans += 2;
            }
        }
        return ans;
    }
};