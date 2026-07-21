// Time:  O(n * r * l)
// Space: O(min(n, l))

// dp
class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        static const int INF = numeric_limits<int>::max();

        int mx = 0;
        for (const auto& x : rules) {
            mx = max(mx, static_cast<int>(size(x[1])));
        }
        const auto& w = min(mx, static_cast<int>(size(source))) + 1;
        vector<int> dp(w, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            dp[(i - 1 + w) % w] = INF;
            if (dp[i % w] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % w] = min(dp[(i + 1) % w], dp[i % w]);
            }
            for (int j = 0; j < size(rules); ++j) {
                if (i + size(rules[j][0]) >= size(source) + 1) {
                    continue;
                }
                int c = costs[j];
                const auto& p = rules[j][0], &r = rules[j][1];
                bool ok = true;
                for (int k = 0; k < size(p); ++k) {
                    if (r[k] != target[i + k]) {
                        ok = false;
                        break;
                    }
                    if (p[k] == '*') {
                        ++c;
                    } else if (p[k] != source[i + k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[(i + size(p)) % w] = min(dp[(i + size(p)) % w], dp[i % w] + c);
                }
            }
        }
        return dp[size(source) % w] != INF ? dp[size(source) % w] : -1;
    }
};


// Time:  O(n * r * l)
// Space: O(n)
// dp
class Solution2 {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(source) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            for (int j = 0; j < size(rules); ++j) {
                if (i + size(rules[j][0]) >= size(dp)) {
                    continue;
                }
                int c = costs[j];
                const auto& p = rules[j][0], &r = rules[j][1];
                bool ok = true;
                for (int k = 0; k < size(p); ++k) {
                    if (r[k] != target[i + k]) {
                        ok = false;
                        break;
                    }
                    if (p[k] == '*') {
                        ++c;
                    } else if (p[k] != source[i + k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i + size(p)] = min(dp[i + size(p)], dp[i] + c);
                }
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
