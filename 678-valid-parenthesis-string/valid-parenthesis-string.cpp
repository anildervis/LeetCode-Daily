class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')')
            {
                if (!left.empty())
                    left.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
            }
            else
                star.push(i);
        }

        while (!left.empty())
        {
            if (!star.empty() && star.top() > left.top())
            {
                star.pop();
                left.pop();
            }
            else
                return false;
        }

        return true;
    }
};