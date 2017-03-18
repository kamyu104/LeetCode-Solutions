// Time:  O(k) ~ O(k * r^2)
// Space: O(r)

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> lookup;
        for (int i = 0; i < ring.size(); ++i) {
            lookup[ring[i]].emplace_back(i);
        }

        vector<vector<int>> dp(2, vector<int> (ring.size()));
        vector<int> tmp(1, 0);
        vector<int> *prev = &tmp;
        for (int i = 1; i <= key.size(); ++i) {
            fill(dp[i % 2].begin(), dp[i % 2].end(), numeric_limits<int>::max());
            for (const auto& j : lookup[key[i - 1]]) {
                for (const auto& k : *prev) {
                    int min_dist = min((k + ring.size() - j) % ring.size(),
                                       (j + ring.size() - k) % ring.size()) +
                                   dp[(i - 1) % 2][k];
                    dp[i % 2][j] = min(dp[i % 2][j], min_dist);
                }
            }
            prev = &lookup[key[i - 1]];
        }
        return *min_element(dp[key.size() % 2].begin(), dp[key.size() % 2].end()) + key.size();
    }
};
