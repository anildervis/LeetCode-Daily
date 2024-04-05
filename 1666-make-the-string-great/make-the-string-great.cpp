class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (st.empty())
                st.push(s[i]);
            else if (st.top() - 32 == int(s[i]) or st.top() + 32 == int(s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};