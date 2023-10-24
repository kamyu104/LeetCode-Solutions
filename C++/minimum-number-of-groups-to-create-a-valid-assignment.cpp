// Time:  O(min(cnt.values()) * n/min(cnt.values())) = O(n)
// Space: O(n)

// linear search, greedy, math
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };
    
        unordered_map<int, int> cnt;
        const auto& count = [&](int x) {
            int result = 0;
            for (const auto& [_, c] : cnt) {
                if (c % x > c / x) {
                    return INF;
                }
                result += ceil_divide(c, x + 1);
            }
            return result;
        };

        for (const auto& x : nums) {
            ++cnt[x];
        }
        int min_cnt = INF;
        for (const auto& [_, c] : cnt) {
            min_cnt = min(min_cnt, c);
        }
        for (int i = min_cnt; i >= 1; --i) {
            const int c = count(i);
            if (c != INF) {
                return c;
            }
        }
        return 0;
    }
};
