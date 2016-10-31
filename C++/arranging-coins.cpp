// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        return static_cast<int>((sqrt(8.0 * n + 1) - 1) / 2);
    }
};

// Time:  O(logn)
// Space: O(1)
class Solution2 {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (2L * n < mid * (mid + 1)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
