class Solution {
public:
    int lengthOfLastWord(string s) {
        int start_idx = s.size() - 1;
        while (s[start_idx] == ' ')
            start_idx--;
        for (int i = start_idx; i >= 0; --i)
            if (s[i] == ' ')
                return start_idx - i;
        return start_idx + 1;
    }
};