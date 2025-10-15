// Time:  precompute: O(r)
//        runtime:    O(nlogx)
// Space: O(r + n)

vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
    vector<int> spf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return spf;
}

const int MAX_NUMS = 1e5;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_NUMS);

// number theory, iterative dfs, freq table
class Solution {
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        const auto& prime_factors = [](int x) {
            int result = 1;
            for (; x != 1; x /= SPF[x]) {
                if (result % SPF[x] == 0) {
                    result /= SPF[x];
                } else {
                    result *= SPF[x];
                }
            }
            return result;
        };

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        unordered_map<int, int> cnt;
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using P = tuple<int, int, int, int, int>;
            vector<P> stk = {{1, 0, -1, -1, 0}};
            while (!empty(stk)) {
                const auto [step, u, p, i, x] = stk.back(); stk.pop_back();
                if (step == 1) {
                    const auto& x = prime_factors(nums[u]);
                    result += cnt[x]++;
                    stk.emplace_back(3, -1, -1, -1, x);
                    stk.emplace_back(2, u, p, 0, 0);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p, i + 1, 0);
                    const auto& v = adj[u][i];
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(1, v, u, -1, 0);
                } else if (step == 3) {
                    --cnt[x];
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  precompute: O(r)
//        runtime:    O(nlogx)
// Space: O(r + n)
// number theory, dfs, freq table
class Solution2 {
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        const auto& prime_factors = [](int x) {
            int result = 1;
            for (; x != 1; x /= SPF[x]) {
                if (result % SPF[x] == 0) {
                    result /= SPF[x];
                } else {
                    result *= SPF[x];
                }
            }
            return result;
        };

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        unordered_map<int, int> cnt;
        const function<int64_t (int, int)> dfs = [&](int u, int p) {
            const auto& x = prime_factors(nums[u]);
            int64_t result = cnt[x]++;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                result += dfs(v, u);
            }
            --cnt[x];
            return result;
        };

        return dfs(0, -1);
    }
};
