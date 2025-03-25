// Time:  O(n * m)
// Space: O(1)

// prefix sum, greedy
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int64_t result = 0;
        for (int i = 1; i < size(mana); ++i) {
            int64_t prefix = 0, mx = 0;
            for (const auto& x : skill) {
                prefix += x;
                mx = max(mx, mana[i - 1] * prefix - mana[i] * (prefix - x));
            }
            result += mx;
        }
        result += mana.back() * accumulate(cbegin(skill), cend(skill), 0ll);
        return result;
    }
};
