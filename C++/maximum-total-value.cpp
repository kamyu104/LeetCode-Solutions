// Time:  O(nlogr)
// Space: O(1)

// binary search
class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        static const int MOD = 1e9 + 7;

        const auto& binary_search = [](int left, int right, const auto& check) {
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

        const auto& total = [&](int x) {
            int result = 0;
            int64_t cnt = 0;
            for (int i = 0; i < size(value); ++i) {
                if (value[i] - x < 0) {
                    continue;
                }
                const int64_t t = (value[i] - x) / decay[i] + 1;
                result = t % 2 == 0
                    ? (result + (value[i] + (value[i] - decay[i] * (t - 1))) * (t / 2)) % MOD
                    : (result + (value[i] - decay[i] * ((t - 1) / 2)) * t) % MOD;
                cnt += t;
            }
            return pair(result, cnt);
        };

        const auto& check = [&](int x) {
            return total(x).second <= m;
        };

        if (check(1)) {
            return total(1).first;
        }
        const auto& x = binary_search(2, ranges::max(value), check);
        auto [result, cnt] = total(x);
        result = (result + (m - cnt) * (x - 1)) % MOD;
        return result;
    }
};
