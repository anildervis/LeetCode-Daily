class Solution {
public:
int trap(vector<int>& height) {
        unordered_map<int, int> water;
        vector<int> prefix(height.size());
        prefix[0] = height[0];
        for (int i = 1; i < height.size(); i++)
            prefix[i] = prefix[i - 1] + height[i];
        stack<pair<int, int>> s;
        s.push({height[0], 0});
        int last_one_index = 0;
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            while (s.size() && s.top().first <= height[i]) {
                last_one_index = s.top().second;
                sum -= water[s.top().second];
                s.pop();
            }
            if (s.size() == 0) {
                water[last_one_index] = min(height[i], height[last_one_index]) * (i - last_one_index - 1) - (prefix[i - 1] - prefix[last_one_index]);
                sum += water[last_one_index];
            } else {
                water[i] = min(s.top().first, height[i]) * (i - s.top().second - 1) - (prefix[i - 1] - prefix[s.top().second]);
                sum += water[i];
            }
            s.push({height[i], i});
        }
        return sum;
    }
};