// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    int countConsistent(vector<int>& nums) {
        const auto& is_superset = [](int a, int b) {
            return (a & b) == b;
        };
        const auto& is_strict_superset = [](int a, int b) {
            return (a & b) == b && a != b;
        };

        vector<int> left, stk;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(stk) && is_superset(nums[stk.back()], nums[i])) {
                stk.pop_back();
            }
            left.emplace_back(!empty(stk) ? stk.back() : -1);
            stk.emplace_back(i);
        }
        int result = 0;
        stk.clear();
        for (int i = size(nums) - 1; i >= 0; --i) {
            while (!empty(stk) && is_strict_superset(nums[stk.back()], nums[i])) {
                stk.pop_back();
            }
            const auto& right = !empty(stk) ? stk.back() : size(nums);
            result += (i - left[i]) * (right - i);
            stk.emplace_back(i);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int countConsistent(vector<int>& nums) {
        int result = size(nums);
        for (int i = 0; i < size(nums); ++i) {
            int mask = nums[i], mn = nums[i];
            for (int j = i + 1; j < size(nums); ++j) {
                mask &= nums[j];
                mn = min(mn, nums[j]);
                if (mask == mn) {
                    ++result;
                }
            }
        }
        return result;
    }
};
