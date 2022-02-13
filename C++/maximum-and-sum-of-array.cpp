// Time:  O(n^3)
// Space: O(n^2)

// weighted bipartite matching solution
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<vector<int>> adj(2 * numSlots, vector<int>(2 * numSlots));
        for (int i = 0; i < 2 * numSlots; ++i) {
            for (int j = 0; j < 2 * numSlots; ++j) {
                adj[i][j] = -((i < size(nums) ? nums[i] : 0) & (1 + j / 2));
            }
        }
        return -hungarian(adj).first;
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

// Time:  O(s * 3^s)
// Space: O(3^s)
// bottom-up dp (hard to implement but faster)
class Solution2 {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        const auto& count = [](int x) {
            int result = 0;
            for (; x; x /= 3) {
                result += x % 3;
            }
            return result;
        };

        vector<int> dp(pow(3, numSlots));
        for (int mask = 1; mask < size(dp); ++mask) {
            const int i = count(mask) - 1;
            const int x = (i < size(nums)) ? nums[i] : 0;
            for (int slot = 1, base = 1; slot <= numSlots; ++slot, base *= 3) {
                if (mask / base % 3) {
                    dp[mask] = max(dp[mask], (x & slot) + dp[mask - base]);
                }
            }
        }
        return dp.back();
    }
};
