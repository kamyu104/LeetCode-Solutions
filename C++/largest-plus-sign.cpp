// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (const auto& mine : mines) {
            lookup.emplace(mine[0], mine[1]);
        }
        vector<vector<int>> dp(N, vector<int>(N));
        int result = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0, l = 0; j < N; ++j) {
                l = lookup.count(make_pair(i, j)) ? 0 : l + 1;
                dp[i][j] = l;
            }
            for (int j = N - 1, l = 0; j >= 0; --j) {
                l = lookup.count(make_pair(i, j)) ? 0 : l + 1;
                dp[i][j] = min(dp[i][j], l);
            }
        }
        
        for (int j = 0; j < N; ++j) {
            for (int i = 0, l = 0; i < N; ++i) {
                l = lookup.count(make_pair(i, j)) ? 0 : l + 1;
                dp[i][j] = min(dp[i][j], l);
            }
            for (int i = N - 1, l = 0; i >= 0; --i) {
                l = lookup.count(make_pair(i, j)) ? 0 : l + 1;
                dp[i][j] = min(dp[i][j], l);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }

private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
};
