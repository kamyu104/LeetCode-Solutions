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

// Time:  O(n)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    int longestAlternating(vector<int>& nums) {
        const auto& cmp = [](int a, int b) {
            return (a > b) - (a < b);
        };

        vector<int> left(size(nums), 1);
        for (int i = 1; i < size(nums); ++i) {
            const auto& diff = cmp(nums[i - 1], nums[i]);
            if (!diff) {
                continue;
            }
            left[i] = (i - 2 >= 0 && cmp(nums[i - 2], nums[i - 1]) == -diff) ? left[i - 1] + 1 : 2;
        }
        vector<int> right(size(nums), 1);
        for (int i = size(nums) - 2; i >= 0; --i) {
            const auto& diff = cmp(nums[i], nums[i + 1]);
            if (!diff) {
                continue;
            }
            right[i] = (i + 2 < size(nums) && cmp(nums[i + 1], nums[i + 2]) == -diff) ? right[i + 1] + 1 : 2;
        }
        int result = ranges::max(left);
        for (int i = 1; i + 1 < size(nums); ++i) {
            const auto& diff = cmp(nums[i - 1], nums[i + 1]);
            if (!diff) {
                continue;
            }
            const auto& l = (i - 2 >= 0 && cmp(nums[i - 2], nums[i - 1]) == -diff) ? left[i - 1] : 1;
            const auto& r = (i + 2 < size(nums) && cmp(nums[i + 1], nums[i + 2]) == -diff) ? right[i + 1] : 1;
            result = max(result, l + r);
        }
        return result;
    }
};
