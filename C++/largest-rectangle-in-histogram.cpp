// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> increasing_heights;
        int max_area = 0;

        for (int i = 0; i <= heights.size();) {
            if (increasing_heights.empty() ||
                (i < heights.size() && heights[i] > heights[increasing_heights.top()])) {
                increasing_heights.emplace(i);
                ++i;
            } else {
                auto h = heights[increasing_heights.top()];
                increasing_heights.pop();
                auto left = increasing_heights.empty() ? -1 : increasing_heights.top();
                max_area = max(max_area, h * (i - left - 1));
            }
        }

        return max_area;
    }
};
