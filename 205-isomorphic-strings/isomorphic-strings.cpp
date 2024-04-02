class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> w1;
        unordered_map<int, int> w2;
        int counter = 0;

        for (int i = 0; i < min(s.size(), t.size()); ++i)
        {
            if (w1[s[i]] != 0)
            {
                if (w1[s[i]] == w2[t[i]])
                    continue;
                return false;
            }
            else
            {
                if (w2[t[i]] != 0)
                    return false;
                w1[s[i]] = ++counter;
                w2[t[i]] = counter;
            }
        }

        return s.size() == t.size() ? true : false;
    }
};