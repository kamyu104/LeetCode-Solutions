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
        uint64_t left = 1, right = n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(mid, n)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(uint64_t mid, uint64_t n) {
        return mid <= 2L * n / (mid + 1);
    }
};
