// Time:  O(qlogr)
// Space: O(1)

// greedy
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        int64_t result = 0;
        for (const auto &q : queries) {
            const int64_t l = q[0], r = q[1];
            int64_t total = 0;
            for (int64_t base = 1, i = 1; base <= r; base *= 4, ++i) { 
                const int nl = max(l, base), nr = min(r, base * 4 - 1);
                if (nl <= nr) {
                    total += i * (nr - nl + 1);
                }
            }
            result += (total + 1) / 2;
        }
        return result;
    }
};
