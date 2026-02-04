// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int result = 1, up1 = 1, up0 = 1, down1 = 1, down0 = 1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] < nums[i + 1]) {
                tie(up1, up0, down1, down0) = tuple(down1 + 1, down0 + 1, down0, 1);
            } else if (nums[i] > nums[i + 1]) {
                tie(up1, up0, down1, down0) = tuple(up0, 1, up1 + 1, up0 + 1);
            } else {
                tie(up1, up0, down1, down0) = tuple(up0, 1, down0, 1);
            }
            result = max({result, up1, down1});
        }
        return result;
    }
};
