// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int j = size(nums) - 1;
        for (; j >= 1; --j) {
            if (!(nums[j - 1] < nums[j])) {
                break;
            }
        }
        if (j == 0) {
            return (size(nums) + 1) * size(nums) / 2;
        }
        int64_t result = size(nums) - j + 1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            while (j < size(nums) && !(nums[i] < nums[j])) {
                ++j;
            }
            result += size(nums) - j + 1;
            if (!(nums[i] < nums[i + 1])) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(n^3)
// Space: O(1)
// brute force
class Solution2 {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int64_t result = 0;
        for (int left = 0; left < size(nums); ++left) {
            for (int right = left; right < size(nums); ++right) {
                bool check = left == 0 || right == size(nums) - 1 || nums[left - 1] < nums[right + 1];
                if (!check) {
                    continue;
                }
                for (int i = 0; i + 1 < left; ++i) {
                    if (!(nums[i] < nums[i + 1])) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    continue;
                }
                for (int i = right + 1; i + 1 < size(nums); ++i) {
                    if (!(nums[i] < nums[i + 1])) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    continue;
                }
                ++result;
            }
        }
        return result;
    }
};
