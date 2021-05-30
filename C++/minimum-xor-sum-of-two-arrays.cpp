// Time:  O(n^3)
// Space: O(n^2)

// weighted bipartite matching solution
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> adj(size(nums1), vector<int>(size(nums2)));
        for (int i = 0; i < size(nums1); ++i) {
            for (int j = 0; j < size(nums2); ++j) {
                adj[i][j] = nums1[i] ^ nums2[j];
            }
        }
        return hungarian(adj).first;
    }

private:
    // Template modified from:
    // https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/WeightedMatching.h
    pair<int, vector<int>> hungarian(const vector<vector<int>> &a) {  // Time: O(n^2 * m), Space: O(n + m)
        if (a.empty()) return {0, {}};
        int n = size(a) + 1, m = size(a[0]) + 1;
        vector<int> u(n), v(m), p(m), ans(n - 1);
        for (int i = 1; i < n; ++i) {
            p[0] = i;
            int j0 = 0; // add "dummy" worker 0
            vector<int> dist(m, numeric_limits<int>::max()), pre(m, -1);
            vector<bool> done(m + 1);
            do { // dijkstra
                done[j0] = true;
                int i0 = p[j0], j1, delta = numeric_limits<int>::max();
                for (int j = 1; j < m; ++j) {
                    if (!done[j]) {
                        auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
                        if (dist[j] < delta) delta = dist[j], j1 = j;
                    }
                }
                for (int j = 0; j < m; ++j) {
                    if (done[j]) u[p[j]] += delta, v[j] -= delta;
                    else dist[j] -= delta;
                }
                j0 = j1;
            } while (p[j0]);
            while (j0) { // update alternating path
                int j1 = pre[j0];
                p[j0] = p[j1], j0 = j1;
            }
        }
        for (int j = 1; j < m; ++j) if (p[j]) ans[p[j] - 1] = j - 1;
        return {-v[0], ans}; // min cost
    }
};

// Time:  O(n * 2^n)
// Space: O(2^n)
// dp solution
class Solution2 {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> dp(1 << size(nums2), {numeric_limits<int>::max(), numeric_limits<int>::max()});
        dp[0] = {0, 0};
        for (int mask = 0; mask < size(dp); ++mask) {
            for (int i = 0, bit = 1; i < size(nums2); ++i, bit <<= 1) {
                if ((mask & bit) == 0) {
                    dp[mask | bit] = min(dp[mask | bit], {dp[mask].first + (nums1[dp[mask].second] ^ nums2[i]), dp[mask].second + 1});
                }
            }
        }
        return dp.back().first;
    }
};
