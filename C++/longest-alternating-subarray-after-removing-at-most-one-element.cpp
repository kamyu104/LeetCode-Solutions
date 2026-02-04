// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int result = 1, up1 = 1, up = 1, down1 = 1, down = 1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] < nums[i + 1]) {
                tie(up1, up, down1, down) = tuple(down1 + 1, down + 1, down, 1);
            } else if (nums[i] > nums[i + 1]) {
                tie(up1, up, down1, down) = tuple(up, 1, up1 + 1, up + 1);
            } else {
                tie(up1, up, down1, down) = tuple(up, 1, down, 1);
            }
            result = max({result, up1, down1});
        }
        return result;
    }
};
