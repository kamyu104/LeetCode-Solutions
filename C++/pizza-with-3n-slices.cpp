// Time:  O(n^2)
// Space: O(n)

// [observation]
// 1. we can never take two adjacent slices
// 2. if we want some set of N / 3 non-adjacent slices, there is always a way to take
//
// [proof]
// - for N = 3, it is obviously true.
// - for N' = N + 3,
//   - because it's impossible to have only one unwanted slices between all wanted slices.
//     if it's true, there will be 3N'/2 unwanted slices rather than 2N' unwanted ones, -><-
//   - so we can always find a sequence of two unwanted slices with one wanted slice
//     to take firstly, then we can find a way to take the remaining N ones by induction, QED

// better optimized space
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        return max(maxSizeSlicesLinear(slices, 0, slices.size() - 1),
                   maxSizeSlicesLinear(slices, 1, slices.size()));
    }

private:
    int maxSizeSlicesLinear(const vector<int>& slices, int start, int end) {
        vector<vector<int>> dp(2, vector<int>(slices.size() / 3 + 1));
        for (int i = start; i < end; ++i) {
            for (int j = min(((i - start + 1) - 1) / 2 + 1, int(slices.size()) / 3);
                 j >= 1;
                 --j) {
                dp[i % 2][j] = max(dp[(i - 1 + 2) % 2][j],
                                   dp[(i - 2 + 2) % 2][j - 1] + slices[i]);
            }
        }
        return dp[(end - 1) % 2][slices.size() / 3];
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    int maxSizeSlices(vector<int>& slices) {
        return max(maxSizeSlicesLinear(slices, 0, slices.size() - 1),
                   maxSizeSlicesLinear(slices, 1, slices.size()));
    }

private:
    int maxSizeSlicesLinear(const vector<int>& slices, int start, int end) {
        vector<vector<int>> dp(3, vector<int>(slices.size() / 3 + 1));
        for (int i = start; i < end; ++i) {
            for (int j = 1;
                 j <= min(((i - start + 1) - 1) / 2 + 1, int(slices.size()) / 3);
                 ++j) {
                dp[i % 3][j] = max(dp[(i - 1 + 3) % 3][j],
                                   dp[(i - 2 + 3) % 3][j - 1] + slices[i]);
            }
        }
        return dp[(end - 1) % 3][slices.size() / 3];
    }
};
