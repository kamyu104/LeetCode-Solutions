// Time:  O(k^3 * n^2)
// Space: O(k^2 * n)

class Solution {
public:
    double getProbability(vector<int>& balls) {
        unordered_map<pair<int, int>, uint64_t, PairHash<int>> dp;
        unordered_map<int, vector<int>> lookup;
        dp[pair(0, 0)] = 1;  // dp[i, j] is the number of ways with number difference i and color difference j
        for (const auto& n : balls) {  // O(k) times
            unordered_map<pair<int, int>, uint64_t, PairHash<int>> new_dp;
            for (const auto& kvp : dp) {  // O(k^2 * n) times
                const auto& cands = candidates(n, &lookup);
                const auto& [ndiff, cdiff] = kvp.first;
                for (int k = 0; k < cands.size(); ++k) {  // O(n) times
                    const auto& new_ndiff = ndiff + (k - (n - k));
                    const auto& new_cdiff = (k == 0) ? cdiff - 1 : ((k == n) ? cdiff + 1 : cdiff);
                    new_dp[pair(new_ndiff, new_cdiff)] += kvp.second * cands[k];
                }
            }
            dp = move(new_dp);
        }
        const auto& total = accumulate(cbegin(balls), cend(balls), 0);
        return double(dp[pair(0, 0)]) / nCr(total, total / 2);
    }

private:
    uint64_t nCr(int n, int r) {
        if (n - r < r) {
            return nCr(n, n - r);
        }
        uint64_t c = 1;
        for (int k = 1; k <= r; ++k) {
            c *= n - k + 1;
            c /= k;
        }
        return c;
    }
        
    vector<int> candidates(int n, unordered_map<int, vector<int>> *lookup) {  // Time: O(n^2), Space: O(n)
        if (!lookup->count(n)) {
            for (int i = 0; i <= n; ++i) {
                (*lookup)[n].emplace_back(nCr(n, i));
            }
        }
        return (*lookup)[n];
    }
    
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
