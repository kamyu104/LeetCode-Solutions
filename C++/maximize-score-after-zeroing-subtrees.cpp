// Time:  O(n)
// Space: O(n)

// tree dp
class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        static const auto& INF = numeric_limits<int>::max();

        vector<int> cnt(size(parent));
        for (int i = 1; i < size(parent); ++i) {
            ++cnt[parent[i]];
        }
        vector<int> dp1(size(parent), INF);
        auto dp2 = score;
        for (int i = 0; i < size(parent); ++i) {
            for (int u = i; cnt[u] == 0; u = parent[u]) {
                if (dp1[u] != INF) {
                    dp2[u] -= op[u] ? dp1[u] : min(dp1[u], 0);
                }
                cnt[u] = -1;
                if (parent[u] == -1) {
                    break;
                }
                dp1[parent[u]] = min(dp1[parent[u]], dp2[u]);
                dp2[parent[u]] += dp2[u];
                --cnt[parent[u]];
            }
        }
        return dp2[0];
    }
};
