// Time:  O(logr * logk)
// Space: O(1)

// binary search, fast exponentiation
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        const auto& binary_search_right = [](int left, int right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& count = [&](int right) {
            return binary_search_right(0, right, [&](int x) {
                return pow(x, k) <= right;
            }) - 0 + 1;
        };

        return count(r) - count(l - 1);
    }
};
