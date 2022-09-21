// Time:  O(n)
// Space: O(1)

// greedy, constructive algorithms
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int64_t result = 0, last = 0;
        for (const auto& t : transactions) {
            last = max(last, static_cast<int64_t>(t[0] - max(t[0] - t[1], 0)));  // t[0] - max(t[0] - t[1], 0) == min(t[0], t[1])
            result += max(t[0] - t[1], 0);
        }
        result += last;
        return result;
    }
};
