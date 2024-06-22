class Solution {
public:
    int findK(vector<int>& nums, int num) {
        int count = 0;
        int in_array = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > num)
                count++;
            if (nums[i] == num)
                in_array = 1;
        }

        return in_array * (count + 1);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = -1e4, right = 1e4;
        int mid = (right - left) / 2 + left;

        while (left < right)
        {
            int count = findK(nums, mid);

            if (count >= 0 and count == k)
                return mid;
            
            count = abs(count);
            
            if (count <= k)
                right = mid;
            else
                left = mid + 1;

            mid = (right - left) / 2 + left;
        }

        return mid;
    }
};