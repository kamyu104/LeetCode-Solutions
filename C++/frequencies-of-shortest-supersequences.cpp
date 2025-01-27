// Time:  O(n + k^2 * 2^k), k = len(char_to_int) <= 16
// Space: O(k^2)

// bitmasks, topological sort
class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        vector<int> char_to_int(26, -1), int_to_char(26), indegree;
        const auto& f = [&](int x) {
            x -= 'a';
            if (char_to_int[x] == -1) {
                int_to_char[size(indegree)] = x;
                char_to_int[x] = size(indegree);
                indegree.emplace_back(0);
            }
            return char_to_int[x];
        };

        vector<vector<int>> adj(26);
        for (const auto& w : words) {
            adj[f(w[0])].emplace_back(f(w[1]));
            ++indegree[f(w[1])];
        }
        pair<int, vector<vector<int>>> ans = {numeric_limits<int>::max(), {}};
        const auto& topological_sort = [&](const auto& cnt) {
            const auto& total = accumulate(cbegin(cnt), cend(cnt), 0);
            if (total > ans.first) {
                return;
            }
            vector<int> new_cnt(cnt);
            vector<int> new_indgree(indegree);
            vector<bool> lookup(size(cnt));
            vector<int> q;
            for (int u = 0; u < size(indegree); ++u) {
                if (!new_indgree[u] || new_cnt[u] == 2) {
                    --new_cnt[u];
                    lookup[u] = true;
                    q.emplace_back(u);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (--new_indgree[v]) {
                            continue;
                        }
                        --new_cnt[v];
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            if (any_of(cbegin(new_cnt), cend(new_cnt), [](const auto& x) {
                return x != 0;
                })) {
                return;
            }
            if (ans.first > total) {
                ans.first = total;
                ans.second.clear();
            }
            ans.second.emplace_back(cnt);
        };

        for (int mask = 0; mask < (1 << size(indegree)); ++mask) {
            vector<int> cnt(size(indegree), 1);
            for (int i = 0; i < size(indegree); ++i) {
                if (mask & (1 << i)) {
                    cnt[i] = 2;
                }
            }
            topological_sort(cnt);
        }
        vector<vector<int>> result;
        for (const auto& cnt : ans.second) {
            vector<int> new_cnt(26);
            for (int i = 0; i < size(cnt); ++i) {
                new_cnt[int_to_char[i]] = cnt[i];
            }
            result.emplace_back(new_cnt);
        }
        return result;
    }
};
