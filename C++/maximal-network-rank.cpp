// Time:  O(m + n + k^2), k is the number of values greater or equal to top2
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
        sorted_idx = counting_sort(sorted_idx,
                                   [&degree](const auto& x) {
                                       return degree[x];
                                   },
                                   true);
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

 private:
    vector<int> counting_sort(const vector<int>& arr, const function<int(int)>& key, bool is_reverse) {
        static const int MAX_N = 100;
        static const int MAX_NUM = MAX_N - 1;
        vector<int> count(MAX_NUM + 1);
        for (const auto& x : arr) {
            ++count[key(x)];
        }
        for (int i = 1; i < size(count); ++i) {
            count[i] += count[i - 1];
        }
        vector<int> result(size(arr));
        if (!is_reverse) {
            for (int i = size(arr) - 1; i >= 0; --i) {  // stable sort
                result[--count[key(arr[i])]] = arr[i];
            }
        } else {
            for (const auto& x : arr) {  // stable sort
                result[--count[key(x)]] = x;
            }
            reverse(begin(result), end(result));
        }
        return result;
    }
};

// Time:  O(m + nlogn + k^2), k is the number of values greater or equal to top2
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
class Solution3 {
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
