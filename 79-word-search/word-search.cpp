class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int row, col;
    bool dfs(vector<vector<char>>& board, string& word, vector<bool>& vis, int all_in_all)
    {
        vis[all_in_all % 36] = true;
        int old_r = (all_in_all % 36) / 6;
        int old_c = all_in_all % 6;
        int word_idx = all_in_all / 36;
        if (word_idx == word.size())
            return true;
        bool ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int new_r = old_r + dx[k];
            int new_c = old_c + dy[k];
            if (new_r < row and new_r >= 0 and new_c < col and new_c >= 0 and !vis[new_r * 6 + new_c] and board[new_r][new_c] == word[word_idx])
                ans |= dfs(board, word, vis, 36 * (word_idx + 1) + 6 * new_r + new_c);
        }
        vis[all_in_all % 36] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        vector<bool> vis(36);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != word[0])
                    continue;
                if (dfs(board, word, vis, 36 + 6 * i + j))
                    return true;
            }
        }
        return false;
    }
};