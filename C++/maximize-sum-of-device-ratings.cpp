// Time:  O(m * n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        const auto& top2 = [](const auto& nums) {  // Time: O(k * n)
            int mn1 = numeric_limits<int>::max(), mn2 = numeric_limits<int>::max();
            for (auto x : nums) {
                if (x < mn1) {
                    mn2 = mn1;
                    mn1 = x;
                } else if (x < mn2) {
                    mn2 = x;
                }
            }
            return pair(mn1, mn2);
        };

        if (size(units[0]) == 1) {
            return accumulate(cbegin(units), cend(units), 0LL, [](const auto& accu, const auto& row) {
                return accu + row[0];
            });
        }
        int64_t total = 0;
        int mn1 = numeric_limits<int>::max(), mn2 = numeric_limits<int>::max();
        for (const auto& row : units) {
            const auto& [m1, m2] = top2(row);
            total += m2;
            mn1 = min(mn1, m1);
            mn2 = min(mn2, m2);
        }
        return total - mn2 + mn1;
    }
};
