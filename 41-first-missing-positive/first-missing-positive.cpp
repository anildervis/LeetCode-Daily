class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto &x : nums)
            mp[x] = 1;
        for (int i = 1; i < 2147483647; i++)
            if (mp[i] != 1)
                return i;
        return 0;
    }
};