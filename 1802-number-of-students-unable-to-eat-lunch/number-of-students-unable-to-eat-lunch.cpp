class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        stack<int> sw;

        for (auto &x : students)
            st.push(x);

        for (int i = sandwiches.size() - 1; i >= 0; --i)
            sw.push(sandwiches[i]);
        
        int turn = 0;
        int top;
        while (turn != st.size())
        {
            if (st.front() == sw.top())
            {
                st.pop();
                sw.pop();
                turn = 0;
            }
            else
            {
                top = st.front();
                st.pop();
                st.push(top);
                turn++;
            }
        }

        return st.size();
    }
};