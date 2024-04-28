class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int capacity = 0;
        for (int i = 0; i < height.size(); i++)
        {
            capacity = max(capacity, min(height[l], height[r]) * (r - l));
            if (height[l] > height[r])
                r -= 1;
            else
                l += 1;
        }
        return capacity;
    }
};