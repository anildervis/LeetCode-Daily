class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = -1;
        vector<vector<int>> mtx(matrix.size(), vector<int> (matrix[0].size(), 0));
        for (int j = 0; j < mtx.size(); j++)
        {
            for (int i = mtx[0].size() - 1; i >= 0; i--)
            {
                if (matrix[j][i] == '0')
                    m = -1;
                else if (m == -1)
                {
                    m = i;
                    mtx[j][i] = 1;
                }
                else
                    mtx[j][i] = m - i + 1;
            }
            m = -1;
        }

        vector<int> l(mtx.size()), r(mtx.size());
        int ans = 0;
        for (int i = 0; i < mtx[0].size(); i++)
        {
            stack<pair<int, int>> s1;
            for (int j = 0; j < mtx.size(); j++)
            {
                if (matrix[j][i] == '0')
                {
                    while (!s1.empty())
                    {
                        l[s1.top().second] = (j - s1.top().second) * s1.top().first;
                        s1.pop();
                    }
                    continue;
                }

                while (!s1.empty() && mtx[j][i] < s1.top().first)
                {
                    l[s1.top().second] = (j - s1.top().second) * s1.top().first;
                    s1.pop();
                }

                s1.push({mtx[j][i], j});
            }
            while (!s1.empty())
            {
                l[s1.top().second] = (mtx.size() - s1.top().second) * s1.top().first;
                s1.pop();
            }
            
            stack<pair<int, int>> s2;
            for (int j = mtx.size() - 1; j >= 0; j--)
            {
                if (mtx[j][i] == '0')
                {
                    while (!s2.empty())
                    {
                        r[s2.top().second] = (s2.top().second - j) * s2.top().first;
                        s2.pop();
                    }
                    continue;
                }

                while (!s2.empty() && mtx[j][i] < s2.top().first)
                {
                    r[s2.top().second] = (s2.top().second - j) * s2.top().first;
                    s2.pop();
                }

                s2.push({mtx[j][i], j});
            }
            while (!s2.empty())
            {
                r[s2.top().second] = (s2.top().second + 1) * s2.top().first;
                s2.pop();
            }

            for (int j = 0; j < mtx.size(); j++)
                ans = max(ans, l[j] + r[j] - mtx[j][i]);
        }
        
        return ans;
    }
};