class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        vector<int> v(s.size());
        int l = 0, r = 0;

        while (true)
        {
            while (l < s.size() and s[l] != '(') l++;
            if (l == s.size()) break;

            while (r < l or (r < s.size() and s[r] != ')')) r++;
            if (r == s.size()) break;

            v[l] = 1;
            v[r] = 1;
            l++; r++;
        }

        for (int i = 0; i < s.size(); i++)
            if ((s[i] != '(' and s[i] != ')') or v[i])
                res += s[i];

        return res;
    }
};