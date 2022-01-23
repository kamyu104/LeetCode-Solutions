// Time:  O(n)
// Space: O(1)

// greedy, combinatorics
class Solution {
public:
    int numberOfWays(string corridor) {
        static const int MOD = 1e9 + 7;
        int64_t result = 1;
        int cnt = 0;
        for (int i = 0, j = -1; i < size(corridor); ++i) {
            if (corridor[i] != 'S') {
                continue;
            }
            if (++cnt >= 3 && cnt % 2) {
                result = (result * (i - j)) % MOD;
            }
            j = i;
        }
        return cnt && cnt % 2 == 0 ? result : 0;
    }
};
