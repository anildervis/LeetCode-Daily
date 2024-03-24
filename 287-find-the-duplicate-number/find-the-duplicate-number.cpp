class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> mp(1e5 + 1);
        for (auto &num : nums)
        {
            if (mp[num] != 0)
                return num;
            mp[num] = 1;
        }
        return nums[0];
    }
};