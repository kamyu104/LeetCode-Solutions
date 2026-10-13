// Time:  O(n * l + k * t + n * l * k + n * 2^k + n * l * logk + nlogn) = O(n * l + nlogn), k = 10
// Space: O(k * t + n + k * 2^k) = O(k * t)

// trie, dp, bitmask, heap
class Trie {
public:
    Trie() {
        new_node();
    }

    void add(const string& s, int i) {
        int curr = 0;
        for (const auto& c : s) {
            const auto& x = c - 'a';
            if (nodes_[curr][x] == -1) {
                nodes_[curr][x] = new_node();
            }
            curr = nodes_[curr][x];
        }
        nodes_[curr].back() = i;
    }

    const vector<vector<int>>& nodes() const {
        return nodes_;
    }

private:
    int new_node() {
        nodes_.emplace_back(11, -1);
        return size(nodes_) - 1;
    }

    vector<vector<int>> nodes_;
};

vector<int> merge(const vector<vector<int>>& lists) {
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> min_heap;
    size_t total = 0;
    for (int i = 0; i < size(lists); ++i) {
        min_heap.emplace(lists[i][0], i, 0);
        total += size(lists[i]);
    }
    vector<int> result;
    result.reserve(total);
    while (!empty(min_heap)) {
        const auto [x, i, j] = min_heap.top(); min_heap.pop();
        result.emplace_back(x);
        if (j + 1 < size(lists[i])) {
            min_heap.emplace(lists[i][j + 1], i, j + 1);
        }
    }
    return result;
}

class Solution {
public:
    int minInversions(vector<string>& words, vector<int>& target) {
        static const int K = 10;
        vector<int> lookup(size(words));
        for (int i = 0; i < size(words); ++i) {
            lookup[target[i]] = i;
        }
        Trie trie;
        for (int i = 0; i < size(words); ++i) {
            trie.add(words[i], i);
        }
        const auto& nodes = trie.nodes();
        int result = 0;
        vector<vector<int>> cost_total(1 << K, vector<int>(K));
        vector<int> dp(1 << K);
        vector<vector<int>> cost(K, vector<int>(K));
        vector<vector<int>> merged(size(nodes));
        vector<vector<int>> lists;
        lists.reserve(K + 1);
        for (int u = size(nodes) - 1; u >= 0; --u) {
            const auto& node = nodes[u];
            lists.clear();
            for (int c = 0; c < K; ++c) {
                const auto& v = node[c];
                if (v != -1) {
                    lists.emplace_back(std::move(merged[v]));
                }
            }
            if (size(lists) >= 2) {
                for (int a = 0; a < size(lists); ++a) {  // Total Time: O(k * n * l)
                    for (int b = a + 1; b < size(lists); ++b) {
                        int cnt = 0, i = 0;
                        for (const auto& x : lists[a]) {
                            for (; i < size(lists[b]) && lists[b][i] < x; ++i);
                            cnt += i;
                        }
                        cost[a][b] = cnt;
                        cost[b][a] = size(lists[a]) * size(lists[b]) - cnt;
                    }
                }
                const int total = 1 << size(lists);
                dp[0] = 0;
                fill_n(begin(cost_total[0]), size(lists), 0);
                for (int mask = 1; mask < total; ++mask) {  // Total Time: O(k * 2^k * ((n - 1) / (k - 1))) = O(n * 2^k)
                    const uint32_t low = mask & -mask;
                    const auto& a = bit_width(low) - 1;
                    for (int c = 0; c < size(lists); ++c) {
                        cost_total[mask][c] = cost_total[mask ^ low][c] + cost[a][c];
                    }
                    int mn = numeric_limits<int>::max();
                    for (int c = 0; c < size(lists); ++c) {
                        if (mask & (1 << c)) {
                            mn = min(mn, dp[mask ^ (1 << c)] + cost_total[mask ^ (1 << c)][c]);
                        }
                    }
                    dp[mask] = mn;
                }
                result += dp[total - 1];
            }
            const auto& idx = node.back();
            if (idx != -1) {
                lists.push_back({lookup[idx]});
            }
            merged[u] = merge(lists);  // Total Time: O(n * l * logk)
            if (idx != -1) {  // Total Time: O(nlogn)
                result += distance(begin(merged[u]), ranges::lower_bound(merged[u], lookup[idx]));
            }
        }
        return result;
    }
};
