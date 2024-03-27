class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        int product = 1;

        while (r < nums.size())
        {
            if (l > r)
            {
        		r++;
                continue;
            }    
            if (product < k)
            {
                ans += r - l;
                product *= nums[r];
                r++;
            }
            else
            {
                if (l - r == 0)
                {
                    product *= nums[r];
                    r++;
                }
                product /= nums[l];
                l++;
            }
        }
        
        while (product >= k && l < nums.size())
        {
            product /= nums[l];
            l++;
        }

        return ans + r - l;
    }
};