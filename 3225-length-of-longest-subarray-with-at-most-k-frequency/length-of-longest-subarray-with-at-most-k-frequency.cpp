class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        stack<int> over_limit;

        int l = 0, r = 0;
        int ans = 0;

        while (r < nums.size())
        {
            if (over_limit.empty())
            {
                mp[nums[r]]++;
                if (mp[nums[r]] == k + 1)
                    over_limit.push(nums[r]);
                else
                    ans = max(ans, r - l + 1);
                r++;
            }
            else
            {
                mp[nums[l++]]--;
                while (!over_limit.empty())
                {
                    if (mp[over_limit.top()] > k)
                        break;
                    over_limit.pop();
                }
            }
        }

        return ans;
    }
};