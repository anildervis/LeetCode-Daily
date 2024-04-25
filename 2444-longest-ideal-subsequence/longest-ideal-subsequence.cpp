class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> chars(26);
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int max_len = 0;
            for (int j = max(s[i] - 'a' - k, 0); j <= min(s[i] - 'a' + k, 25); j++)
                max_len = max(chars[j], max_len);
            chars[s[i] - 'a'] = max_len + 1;
            cout << endl;
        }
        for (auto c : chars)
            ans = max(ans, c);
        return ans;
    }
};