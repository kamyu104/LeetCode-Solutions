// Time:  O(m * log(m * n))
// Space: O(1)

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (count(mid, m, n) >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int count(int target, int m, int n) {
        auto count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(target / i , n);
        }
        return count;
    }
};
