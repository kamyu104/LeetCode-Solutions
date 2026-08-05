// Time:  O(n)
// Space: O(n)

// line sweep, difference array, backward simulation
class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        vector<int64_t> diff(size(monsters));
        for (const auto& b : boosts) {
            diff[b[1]] += b[2];
            if (b[0] - 1 >= 0) {
                diff[b[0] - 1] -= b[2];
            }
        }
        int64_t result = 0;
        for (int64_t i = size(monsters) - 1, bonus = 0; i >= 0; --i) {
            bonus += diff[i];
            result += result ? monsters[i] : max(monsters[i] - bonus, static_cast<int64_t>(0));
        }
        return result;
    }
};
