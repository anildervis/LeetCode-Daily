class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_map <string, int> dis;
        unordered_map <string, bool> vis;
        vector<char> nums = {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        for (auto x : deadends)
            dis[x] = -1;
        if (dis["0000"] == -1) return -1;
        queue <string> q;
        q.push("0000");
        dis["0000"] = 0;
        while (!q.empty())
        {
            string u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if (u == target) break;
            for (int i = 0; i < 4; i++)
            {
                string tmp = u;
                for (int j = 0; j < 2; j++)
                {
                    tmp[i] = nums[u[i] - '0' + 2 * j];
                    if ((dis[tmp] != -1 and dis[tmp] > dis[u]) or dis[tmp] == 0)
                    {
                        dis[tmp] = dis[u] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return dis[target] == 0 ? -1 : dis[target];
    }
};