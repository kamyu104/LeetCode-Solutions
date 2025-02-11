// Time:  O(n * log(m * r))
// Space: O(1)

// binary search, greedy
class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        const auto& ceil_divide = [](int64_t a, int64_t b) {
            return (a + b - 1) / b;
        };

        const auto& binary_search_right = [&](int64_t left, int64_t right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& check = [&](int64_t x) {
            for (int64_t i = 0, prev = 0, cnt = 0; i < size(points); ++i) {
                const auto remain = ceil_divide(x, points[i]) - prev;
                if (remain >= 1) {
                    prev = remain - 1;
                    cnt += 2 * remain - 1;
                } else if (i != size(points) - 1) {
                    prev = 0;
                    ++cnt;
                }
                if (cnt > m) {
                    return false;
                };
            }
            return true;
        };

        return binary_search_right(1, static_cast<int64_t>(ranges::max(points)) * m, check);
    }
};
