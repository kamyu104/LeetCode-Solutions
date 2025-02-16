// Time:  O(nlogr)
// Space: O(1)

// binary search
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        const auto& binary_search = [&](double left, double right, const auto& check) {
            static const double EPS = 1e-5;
            while (right - left > EPS) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        const auto& check = [&](double k) {
            double result = 0;
            for (const auto& s : squares) {
                if (s[1] >= k) {
                    result += static_cast<double>(s[2]) * s[2];
                } else if (s[1] + s[2] <= k) {
                    result -= static_cast<double>(s[2]) * s[2];
                } else {
                    result += static_cast<double>(s[2]) * (((s[1] + s[2]) - k) - (k - s[1]));
                }
            }
            return result <= 0;
        };

        double left = numeric_limits<double>::max();
        double right = numeric_limits<double>::min();
        for (const auto& s : squares) {
            left = min(left, static_cast<double>(s[1]));
            right = max(right, static_cast<double>(s[1] + s[2]));
        }
        return binary_search(left, right, check);
    }
};
