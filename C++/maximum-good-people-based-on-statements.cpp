// Time:  O(n^2 * 2^n)
// Space: O(1)

// brute force, bitmask
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        auto check = [&statements](int mask) {
            for (int i = 0; i < size(statements); ++i) {
                if (((mask >> i) & 1) == 0) {
                    continue;
                } 
                for (int j = 0; j < size(statements[i]); ++j) {
                    if (statements[i][j] != 2 && ((mask >> j) & 1) != statements[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        const int total = 1 << size(statements);
        int result = 0;
        for (int mask = 0; mask < total; ++mask) {
            if (check(mask)) {
                result = max(result, __builtin_popcount(mask));
            }
        }
        return result;
    }
};
