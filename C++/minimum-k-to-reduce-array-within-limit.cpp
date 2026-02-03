// Time:  O(nlogr + nlogn)
// Space: O(1)

// binary search
class Solution {
public:
    int minimumK(vector<int>& nums) {
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

        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        const auto& check = [&](int k) {
            int64_t result = 0;
            for (const auto& x : nums) {
                result += ceil_divide(x, k);
                if (result > static_cast<int64_t>(k) * k) {
                    return false;
                }
            }
            return true;
        };

        const auto& right = max(ranges::max(nums), static_cast<int>(ceil(sqrt(size(nums)))));
        return binary_search(1, right, check);
    }
};
