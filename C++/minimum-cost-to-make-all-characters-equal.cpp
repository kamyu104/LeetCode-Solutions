// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long minimumCost(string s) {
        int64_t result = 0;
        for (int i = 0; i + 1 < size(s); ++i) {
            if (s[i] != s[i + 1]) {
                result += min(i + 1, static_cast<int>(size(s)) - (i + 1));
            }
        }
        return result;
    }
};
