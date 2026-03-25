// Time:  O(n)
// Space: O(n)

// combinatorics, mono stack
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        const auto& is_proper_subset = [](int a, int b) {
            return a != b && (a | b) == b;
        };

        const auto& is_subset = [](int a, int b) {
            return (a | b) == b;
        };

        vector<int> right(size(nums), size(nums));
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (; !empty(stk) && is_subset(nums[stk.back()], nums[i]); stk.pop_back());
            right[i] = !empty(stk) ? stk.back() : size(nums);
            stk.emplace_back(i);
        }
        int64_t result = 0;
        stk.clear();
        for (int64_t i = 0, left = -1; i < size(nums); ++i) {
            for (; !empty(stk) && is_proper_subset(nums[stk.back()], nums[i]); stk.pop_back());
            left = !empty(stk) ? stk.back() : -1;
            stk.emplace_back(i);
            result += (i - left) * (right[i] - i);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// combinatorics, mono stack
class Solution2 {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        const auto& is_proper_subset = [](int a, int b) {
            return a != b && (a | b) == b;
        };

        const auto& is_subset = [](int a, int b) {
            return (a | b) == b;
        };

        vector<int> left(size(nums), -1);
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (; !empty(stk) && !is_proper_subset(nums[i], nums[stk.back()]); stk.pop_back()) {
                left[stk.back()] = i;
            }
            stk.emplace_back(i);
        }
        vector<int> right(size(nums), size(nums));
        stk.clear();
        for (int i = 0; i < size(nums); ++i) {
            for (; !empty(stk) && !is_subset(nums[i], nums[stk.back()]); stk.pop_back()) {
                right[stk.back()] = i;
            }
            stk.emplace_back(i);
        }
        int64_t result = 0;
        for (int64_t i = 0; i < size(nums); ++i) {
            result += (i - left[i]) * (right[i] - i);
        }
        return result;
    }
};
