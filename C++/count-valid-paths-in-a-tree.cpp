// Time:  O(n)
// Space: O(n)

// number theory, tree dp, iterative dfs
class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
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
        };

        const auto& spf = linear_sieve_of_eratosthenes(n);
        const auto& is_prime = [&](int x) {
            return spf[x] == x;
        };
    
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using RET = vector<int64_t>;
            RET ret(2);
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    (*ret) = {1 - is_prime(u + 1), is_prime(u + 1)};
                    stk.emplace_back(2, u, p, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, p, i + 1, nullptr, ret);
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>(2);
                    stk.emplace_back(3, u, p, i, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    result += (*ret)[0] * (*new_ret)[1] + (*ret)[1] * (*new_ret)[0];
                    if (is_prime(u + 1)) {
                        (*ret)[1] += (*new_ret)[0];
                    } else {
                        (*ret)[0] += (*new_ret)[0];
                        (*ret)[1] += (*new_ret)[1];
                    }
                }
            }
            return result;
        };
    
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// number theory, tree dp, dfs
class Solution2 {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
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
        };

        const auto& spf = linear_sieve_of_eratosthenes(n);
        const auto& is_prime = [&](int x) {
            return spf[x] == x;
        };
    
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int64_t result = 0;
        const function<vector<int64_t> (int, int)> dfs = [&](int u, int p) {
            vector<int64_t> cnt = {1 - is_prime(u + 1), is_prime(u + 1)};
            for (const auto v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& new_cnt = dfs(v, u);
                result += cnt[0] * new_cnt[1] + cnt[1] * new_cnt[0];
                if (is_prime(u + 1)) {
                    cnt[1] += new_cnt[0];
                } else {
                    cnt[0] += new_cnt[0];
                    cnt[1] += new_cnt[1];
                }
            }
            return cnt;
        };
    
        dfs(0, -1);
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// number theory, union find
class Solution3 {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
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
        };

        const auto& spf = linear_sieve_of_eratosthenes(n);
        const auto& is_prime = [&](int x) {
            return spf[x] == x;
        };
    
        UnionFind uf(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1;
            if (!is_prime(u + 1) && !is_prime(v + 1)) {
                uf.union_set(u, v);
            }
        }
        int64_t result = 0;
        vector<int64_t> cnt(n, 1);
        for (const auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (is_prime(u + 1) == is_prime(v + 1)) {
                continue;
            }
            if (!is_prime(u + 1)) {
                swap(u, v);
            }
            result += cnt[u] * uf.total(v);
            cnt[u] += uf.total(v);
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , size_(n, 1)  {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            size_[y] += size_[x];
            return true;
        }

        int64_t total(int x) {
            return size_[find_set(x)];
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int64_t> size_;
    };
};
