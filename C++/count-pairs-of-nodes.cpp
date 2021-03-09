// Time:  O(n + e + q)
// Space: O(n + e)

// pure counting solution
class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n + 1);
        unordered_map<pair<int, int>, int, PairHash<int>> shared;
        for (const auto& edge : edges) {
            ++degree[edge[0]];
            ++degree[edge[1]];
            ++shared[pair(min(edge[0], edge[1]), max(edge[0], edge[1]))];
        }
        vector<int> cnt(2 * (*max_element(cbegin(degree) + 1, cend(degree)) + 1));
        unordered_map<int, int> count;
        for (int i = 1; i < size(degree); ++i) {
            ++count[degree[i]];
        }
        for (const auto& [i, count1] : count) {
            for (const auto& [j, count2] : count) {
                if (i < j) {
                    cnt[i + j] += count1 * count2;
                } else if (i == j) {
                    cnt[i + j] += count1 * (count1 - 1) / 2;
                }
            }
        }
        for (const auto& [pair, shared_degree] : shared) {
            const auto& [i, j] = pair;
            --cnt[degree[i] + degree[j]];
            ++cnt[degree[i] + degree[j] - shared_degree];
        }
        for (int i = size(cnt) - 2; i >= 0; --i) {
            cnt[i] += cnt[i + 1];
        }
        vector<int> result;
        for (const auto& q : queries) {
            result.emplace_back(q + 1 < size(cnt) ? cnt[q + 1] : 0);
        }
        return result;
    }
};

// Time:  O(nlogn + q * (n + e))
// Space: O(n + e)
// two pointers solution
class Solution2 {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n + 1);
        unordered_map<pair<int, int>, int, PairHash<int>> shared;
        for (const auto& edge : edges) {
            ++degree[edge[0]];
            ++degree[edge[1]];
            ++shared[pair(min(edge[0], edge[1]), max(edge[0], edge[1]))];
        }
        vector<int> sorted_degree(degree);
        sort(begin(sorted_degree), end(sorted_degree));
        vector<int> result;
        for (const auto& q : queries) {
            int left = 1, right = n;
            int cnt = 0;
            while (left <= right) {
                if (q < sorted_degree[left] + sorted_degree[right]) {
                    cnt += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
            for (const auto& [pair, shared_degree] : shared) {
                const auto& [i, j] = pair;
                if (degree[i] + degree[j] - shared_degree <= q && q < degree[i] + degree[j]) {
                    --cnt;
                }
            }
            result.emplace_back(cnt);
        }
        return result;
    }
};
