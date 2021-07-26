// Time:  O(m^2 * (n + m))
// Space: O(m^2)

// weighted bipartite matching solution
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> cost(size(students), vector<int>(size(mentors)));
        for (int i = 0; i < size(students); ++i) {
            for (int j = 0; j < size(mentors); ++j) {
                cost[i][j] = -score(students[i], mentors[j]);
            }
        }
        return -hungarian(cost).first;
    }

private:
    int score(const vector<int>& s, const vector<int>& m) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            result += int(s[i] == m[i]);
        }
        return result;
    }

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

// Time:  O(m * (n + 2^m))
// Space: O(2^m)
// dp solution
class Solution2 {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const auto& nums1 = masks(students);
        const auto& nums2 = masks(mentors);
        vector<pair<int, int>> dp(1 << size(nums2));
        for (int mask = 0; mask < size(dp); ++mask) {
            for (int i = 0, bit = 1; i < size(nums2); ++i, bit <<= 1) {
                if ((mask & bit) == 0) {
                    dp[mask | bit] = max(dp[mask | bit],
                                         {dp[mask].first + (size(students[0]) - __builtin_popcount(nums1[dp[mask].second] ^ nums2[i])),
                                          dp[mask].second + 1});
                }
            }
        }
        return dp.back().first;
    }

private:
    vector<int> masks(const vector<vector<int>>& vvi) {
        vector<int> result;
        for (const auto& vi : vvi) {
            int mask = 0;
            for (int i = 0, bit = 1; i < size(vi); ++i, bit <<= 1) {
                if (vi[i]) {
                    mask |= bit;
                }
            }
            result.emplace_back(mask);
        }
        return result;
    }
};
