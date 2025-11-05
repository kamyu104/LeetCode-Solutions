// Time:  O(logr + logd)
// Space: O(1)

// binary search, number theory
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        const auto& binary_search = [](int64_t left, int64_t right, const auto& check) {
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

        const auto& l = lcm(r[0], r[1]);
        const auto& check = [&](int64_t t) {
            return t - t / r[0] >= d[0] && t - t/ r[1] >= d[1] && t - t / l >= d[0] + d[1];
        };

        return binary_search(d[0] + d[1], 2ll * (d[0] + d[1]), check);
    }
};
