class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();        
        vector<vector<int>> dp(n, vector<int>(m, 20000));

        for (int i = 0; i < m; i++)
            dp[0][i] = grid[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++)
                    if (k != j)
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][k]);                

        int minSum = INT_MAX;
        for (int j = 0; j < m; j++)
            minSum = min(minSum, dp[n-1][j]);

        return minSum;
    }
};