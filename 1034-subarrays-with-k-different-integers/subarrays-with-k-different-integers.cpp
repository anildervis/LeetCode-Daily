class Solution {
public:
    unordered_map<int, int> count;
    unordered_map<int, int> max_idx;
    int min_index = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    void max_idx_finder(vector<int> &nums, int &ans)
    {
        while (max_idx[nums[pq.top()]] != pq.top())
        {
            int idx = pq.top();
            pq.pop();
            count[nums[idx]]--;
        }
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        int distinct = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push(i);
            max_idx[nums[i]] = i;
            if (count[nums[i]] != 0 && distinct == k)
            {
                max_idx_finder(nums, ans);
                ans += pq.top() - min_index + 1;
            }
            else if (count[nums[i]] == 0 && distinct == k)
            {
                max_idx_finder(nums, ans);
                count[nums[pq.top()]]--;
                min_index = pq.top() + 1;
                pq.pop();
                max_idx_finder(nums, ans);
                ans += pq.top() - min_index + 1;
            }
            else if (count[nums[i]] == 0 && ++distinct == k)
            {
                max_idx_finder(nums, ans);
                ans += pq.top() - min_index + 1;
            }
            count[nums[i]]++;
        }

        return ans;
    }
};