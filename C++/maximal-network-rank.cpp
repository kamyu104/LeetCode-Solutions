// Time:  O(m + nlogn) ~ O(n^2)
// Space: O(m + n)

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        unordered_map<int, unordered_set<int>> adj;
        for (const auto& road : roads) {
            ++degree[road[0]];
            ++degree[road[1]];
            adj[road[0]].emplace(road[1]);
            adj[road[1]].emplace(road[0]);
        }
        vector<int> sorted_idx(n);
        iota(begin(sorted_idx), end(sorted_idx), 0);
        sort(begin(sorted_idx), end(sorted_idx),
             [&degree](const auto& a, const auto& b) {
                 return degree[a] > degree[b];
             });
        int m = 2;
        for (; m < n; ++m) {
            if (degree[sorted_idx[m]] != degree[sorted_idx[1]]) {
                break;
            }
        }
        int result = degree[sorted_idx[0]] + degree[sorted_idx[1]] - 1;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if (degree[sorted_idx[i]] + degree[sorted_idx[j]] - int(adj.count(sorted_idx[i]) && adj[sorted_idx[i]].count(sorted_idx[j])) > result) {
                    return degree[sorted_idx[i]] + degree[sorted_idx[j]] - int(adj.count(sorted_idx[i]) && adj[sorted_idx[i]].count(sorted_idx[j]));
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(m + n)
class Solution2 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        unordered_map<int, unordered_set<int>> adj;
        for (const auto& road : roads) {
            ++degree[road[0]];
            ++degree[road[1]];
            adj[road[0]].emplace(road[1]);
            adj[road[1]].emplace(road[0]);
        }
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result = max(result, degree[i] + degree[j] - int(adj.count(i) && adj[i].count(j)));
            }
        }
        return result;
    }
};
