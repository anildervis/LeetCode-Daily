class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto & x : nums)
        {
            if (mp[x])
                ans.push_back(x);
            mp[x]++;
        }
        return ans;
    }
};