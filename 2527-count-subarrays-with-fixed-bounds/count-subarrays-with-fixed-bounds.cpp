// []
// {}
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_count = 0, max_count = 0;
        int right_bound = 0;
        int left_bound_min = -1;
        int left_bound_max = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK or nums[i] > maxK)
            {
                min_count = 0;
                max_count = 0;
                right_bound = i + 1;
                left_bound_min = -1;
                left_bound_max = -1;
            }
            else if (nums[i] == minK or nums[i] == maxK)
            {
                if (nums[i] == minK)
                {
                    left_bound_min = i;
                    min_count++;
                }
                if (nums[i] == maxK)
                {
                    left_bound_max = i;
                    max_count++;
                }
                if (min_count != 0 and max_count != 0)
                {
                    ans += min(left_bound_min, left_bound_max) - right_bound + 1;
                }
            }
            else if (min_count != 0 and max_count != 0)
            {
                ans += min(left_bound_min, left_bound_max) - right_bound + 1;
            }
        }
        return ans;
    }
};