// Time:  O(nlogn)
// Space: O(1)

// sort, dp, two pointers, sliding window, deque
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        static const int DIST = 2;

        sort(begin(power), end(power));
        deque<pair<int, int64_t>> dp;
        int64_t mx = 0;
        for (const auto& x: power) {
            if (!empty(dp) && dp.back().first == x) {
                dp.back().second += x;
                continue;
            }
            while (!empty(dp) && dp.front().first + DIST < x) {
                mx = max(mx, dp.front().second);
                dp.pop_front();
            }
            dp.emplace_back(x, mx + x);
        }
        return max_element(cbegin(dp), cend(dp), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
    }
};
