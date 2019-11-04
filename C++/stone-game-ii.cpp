// Time:  O(n*(logn)^2)
// Space: O(nlogn)

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        for (int i = piles.size() - 2; i >= 0; --i) {
            piles[i] += piles[i + 1];
        }
        unordered_map<int, unordered_map<int, int>> lookup;
        return dp(piles, &lookup, 0, 1);
    }

private:
    int dp(const vector<int>& piles,
           unordered_map<int, unordered_map<int, int>> *lookup,
           int i, int m) {
        if (i + 2 * m >= piles.size()) {
            return piles[i];
        }
        if (!lookup->count(i) || !(*lookup)[i].count(m)) {
            int min_dp = numeric_limits<int>::max();
            for (int x = 1; x <= 2 * m; ++x) {
                min_dp = min(min_dp, dp(piles, lookup, i + x, max(m, x)));
            }
            (*lookup)[i][m] = piles[i] - min_dp;
        }
        return (*lookup)[i][m];
    }
};
