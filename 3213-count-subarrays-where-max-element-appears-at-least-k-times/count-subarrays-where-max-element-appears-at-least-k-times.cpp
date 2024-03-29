class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(), nums.end());
        queue<int> q;
        int index = 0;
        long long ans = 0;
        int length = nums.size();

        while (index < length)
        {
            if (nums[index] == maximum)
            {
                q.push(index);
                if (q.size() == k + 1)
                    q.pop();
            }
            if (q.size() == k)
                ans += q.front() + 1;
            index++;
        }

        return ans;
    }
};