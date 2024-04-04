class Solution {
public:
    int maxDepth(string s) {
        int cur = 0, ans = 0;
        for (auto &x : s)
        {
            if (x == '(')
            {
                cur++;
                ans = max(ans, cur);
            }
            else if (x == ')')
                cur--;
        }
        return ans;
    }
};