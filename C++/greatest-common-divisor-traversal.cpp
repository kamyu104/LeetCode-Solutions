// Time:  precompute: O(sqrt(r)), r = max(nums)
//        runtime:    O(n * (logr + pi(sqrt(r))) = O(n * (logr + sqrt(r)/log(sqrt(r)))), pi(n) = number of primes in a range [1, n] = O(n/logn) by prime number theorem, see https://en.wikipedia.org/wiki/Prime_number_theorem
// Space: O(sqrt(r) + nlogr)

// linear sieve of eratosthenes, number theory, bfs
vector<int64_t> linear_sieve_of_eratosthenes(int64_t n) {  // Time: O(n), Space: O(n)
    vector<int64_t> spf(n + 1, -1);
    vector<int64_t> primes;
    for (int64_t i = 2; i <= n; ++i) {
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
    return primes;
}

static const int MAX_VALUE = 1e5;
const auto& PRIMES = linear_sieve_of_eratosthenes(sqrt(MAX_VALUE));
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const auto& prime_factors = [&](int x) {
            unordered_map<int, int> factors;
            for (const auto& p : PRIMES) {
                if (p * p > x) {
                    break;
                }
                for (; x % p == 0; x /= p) {
                    ++factors[p];
                }
            }
            if (x != 1) {
                ++factors[x];
            }
            return factors;
        };

        vector<vector<int>> adj(size(nums));
        const auto& bfs = [&]() {
            vector<bool> lookup(size(nums));
            lookup[0] = true;
            vector<int> q = {0};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return all_of(cbegin(lookup), cend(lookup), [](int x) { return x; });
        };

        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            for (const auto& [p, _] : prime_factors(nums[i])) {
                if (!lookup.count(p)) {
                    lookup[p] = i;
                    continue;
                }
                adj[i].emplace_back(lookup[p]);
                adj[lookup[p]].emplace_back(i);
            }
        }
        return bfs();
    }
};
