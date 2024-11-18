// Time:  O(nlogr)
// Space: O(1)

// binary search
class Solution {
public:
    int minDifference(vector<int>& nums) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        int max_diff = 0, left = numeric_limits<int>::max(), right = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != -1) {
                if (i + 1 < size(nums) && nums[i + 1] != -1) {
                    max_diff = max(max_diff, abs(nums[i] - nums[i + 1]));
                }
                continue;
            }
            if (i - 1 < size(nums) && nums[i - 1] != -1) {
                left = min(left, nums[i - 1]);
                right = max(right, nums[i - 1]);
            }
            if (i + 1 < size(nums) && nums[i + 1] != -1) {
                left = min(left, nums[i + 1]);
                right = max(right, nums[i + 1]);
            }
        }

        const auto& check = [&](int d) {
            for (int i = 0, prev = 0, x = left + d, y = right - d, cnt = 0; i < size(nums); ++i) {
                if (nums[i] == -1) {
                    ++cnt;
                    continue;
                }
                if (prev && cnt) {
                    const auto& diff = min(max(abs(prev - x), abs(nums[i] - x)), max(abs(prev - y), abs(nums[i] - y)));
                    if (diff > d && (cnt == 1 || y - x > d)) {
                        return false;
                    }
                }
                prev = nums[i];
                cnt = 0;
            }
            return true;
        };

        return binary_search(max_diff, (right - left) / 2, check);
    }
};
