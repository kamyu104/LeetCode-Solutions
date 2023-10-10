// Time:  O(n)
// Space: O(n)

// graph, prefix sum, two pointers, sliding window
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const auto& find_cycles = [](const auto& adj) {
            vector<pair<int, int>> result;
            vector<int> lookup(size(adj));
            for (int i = 0, idx = 0; i < size(adj); ++i) {
                int u = i, prev = idx;
                while (!lookup[u]) {
                    lookup[u] = ++idx;
                    u = adj[u];
                }
                if (lookup[u] > prev) {
                    result.emplace_back(u, idx - lookup[u] + 1);
                }
            }
            return result;
        };
        
        const auto& cycles = find_cycles(receiver);
        vector<pair<int, int>> lookup(size(receiver), {-1, -1});
        vector<vector<int64_t>> prefixes(size(cycles), vector<int64_t>(1));
        const auto& find_prefixes = [&](const auto& cycles) {
            for (int idx = 0; idx < size(cycles); ++idx) {
                auto [u, l] = cycles[idx];
                for (int i = 0; i < l; ++i) {
                    lookup[u] = {idx, i};
                    prefixes[idx].emplace_back(prefixes[idx][i] + u);
                    u = receiver[u];
                }
            }
        };
        
        const auto& get_sum = [](const auto& prefix, int64_t i, int64_t cnt) {
            const int64_t l = size(prefix) - 1;
            const int64_t q = cnt / l;
            const int64_t r = cnt % l;
            return (q * prefix.back() +
                    (prefix[min(i + r, l)] - prefix[i]) +
                    (prefix[max((i + r) - l, static_cast<int64_t>(0))] - prefix[0]));
        };
        
        const auto& start_inside_cycle = [&]() {
            int64_t result = 0;
            for (auto [u, l] : cycles) {
                for (int _ = 0; _ < l; ++_) {
                    const auto& [idx, i] = lookup[u];
                    result = max(result, get_sum(prefixes[idx], i, k + 1));
                    u = receiver[u];
                }
            }
            return result;
        };
    
        const auto& start_outside_cycle = [&]() {
            int64_t result = 0;
            vector<int> degree(size(receiver));
            for (const auto& x : receiver) {
                ++degree[x];
            }
            for (int u = 0; u < size(receiver); ++u) {
                if (degree[u]) {
                    continue;
                }
                int64_t curr = 0;
                deque<int> dq;
                int v = u;
                while (lookup[v].first == -1) {
                    curr += v;
                    dq.emplace_back(v);
                    if (size(dq) == k + 1) {
                        result = max(result, curr);
                        curr -= dq.front(); dq.pop_front();
                    }
                    v = receiver[v];
                }
                const auto& [idx, i] = lookup[v];
                while (!empty(dq)) {
                    result = max(result, curr + get_sum(prefixes[idx], i, (k + 1) - size(dq)));
                    curr -= dq.front(); dq.pop_front();
                }
            }
            return result;
        };
              
        find_prefixes(cycles);
        return max(start_inside_cycle(), start_outside_cycle());
    }
};

// Time:  O(nlogk)
// Space: O(nlogk)
// binary lifting
class Solution2 {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const auto& bit_length = [](int64_t x) {
            return x != 0 ? 8 * sizeof(x) - __builtin_clzll(x) : 1;
        };

        const int l = bit_length(k + 1);
        vector<vector<int>> P(l, vector<int>(size(receiver)));
        P[0] = receiver;
        vector<vector<int64_t>> S(l, vector<int64_t>(size(receiver)));
        iota(begin(S[0]), end(S[0]), 0);
        for (int i = 1; i < l; ++i) {
            for (int u = 0; u < size(receiver); ++u) {
                P[i][u] = P[i - 1][P[i - 1][u]];
                S[i][u] = S[i - 1][u] + S[i - 1][P[i - 1][u]];
            }
        }
        int64_t result = 0;
        for (int u = 0; u < size(receiver); ++u) {
            int64_t curr = 0;
            for (int i = 0, v = u; i < l; ++i) {
                if ((k + 1) & (1ll << i)) {
                    curr += S[i][v];
                    v = P[i][v];
                }
            }
            result = max(result, curr);
        }
        return result;
    }
};
