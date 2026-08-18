// Time:  O(n + m)
// Space: O(1)

// greedy
class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        const auto& mx = ranges::max(lights);
        int result = 0;
        for (auto x : arrivalTime) {
            x %= period;
            if (x < mx) {
                continue;
            }
            result = max(result, period - x);
        }
        return result;
    }
};
