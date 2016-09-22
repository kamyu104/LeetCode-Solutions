// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int i = 0, j = height.size() - 1;
        int left_height = height[0];
        int right_height = height[height.size() - 1];
        int trap = 0;

        while (i < j) {
            if (left_height < right_height) {
                ++i;
                // Fill in the gap.
                trap += max(0, left_height - height[i]);
                // Update current max height from left.
                left_height = max(left_height, height[i]);
            }
            else {
                --j;
                // Fill in the gap.
                trap += max(0, right_height - height[j]);
                // Update current max height from right.
                right_height = max(right_height, height[j]);
            }
        }

        return trap;
    }
};
