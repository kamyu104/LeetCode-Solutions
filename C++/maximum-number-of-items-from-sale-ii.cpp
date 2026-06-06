// Time:  O(rlogr + nlogn) = O(nlogn), r = max(f for f, _ in items) <= n
// Space: O(r + n) = O(n)

// freq table, sort, greedy
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        static const int NEG_INF = numeric_limits<int>::min();

        int max_f = 0;
        for (const auto& x : items) {
            max_f = max(max_f, x[0]);
        }
        vector<int> cnt(max_f + 1);
        for (const auto& x : items) {
            ++cnt[x[0]];
        }
        vector<int> total(size(cnt));
        for (int i = 1; i < size(cnt); ++i) {
            if (!cnt[i]) {
                continue;
            }
            for (int j = i; j < size(cnt); j += i) {
                total[i] += cnt[j];
            }
        }
        int min_p = numeric_limits<int>::max();
        for (const auto& x : items) {
            min_p = min(min_p, x[1]);
        }
        map<int, int64_t> group;
        for (const auto& x : items) {
            if (x[1] >= 2 * min_p) {
                continue;
            }
            group[x[1]] += total[x[0]] - 1;
        }
        int result = 0;
        for (const auto& [p, x] : group) {
            const auto c = min(static_cast<int64_t>(budget) / p, x);
            result += 2 * c;
            budget -= c * p;
            if (budget < p) {
                break;
            }
        }
        result += budget / min_p;
        return result;
    }
};
