// Time:  O(l)
// Space: O(l)

class Solution {
public:
    string nearestPalindromic(string n) {
        const auto l = n.size();
        vector<long long> candidates;
        candidates.emplace_back(static_cast<long long>(pow(10, l)) + 1);
        candidates.emplace_back(static_cast<long long>(pow(10, l - 1)) - 1);
        auto prefix = stol(n.substr(0, (l + 1) / 2));
        for (long long i = -1; i <= 1; ++i) {
            auto p = to_string(prefix + i);
            auto pp = p + string(p.rbegin() + (l % 2), p.rend());
            candidates.emplace_back(stol(pp));
        }
        long long num = stol(n), closest_val = numeric_limits<long long>::max();
        for (const auto& val : candidates) {
            if (val == num) {
                continue;
            }
            if (abs(val - num) < abs(closest_val - num)) {
                closest_val = val;
            } else if (abs(val - num) == abs(closest_val - num)) {
                closest_val = min(closest_val, val);
            }
        }
        return to_string(closest_val);
    }
};
