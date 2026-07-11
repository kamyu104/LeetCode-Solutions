// Time:  precompute: O(r)
//        runtime:    O(nlogx + f) = O(nlogx), f = sum of distinct prime factors over all nums (<= 7n)
// Space: O(r + n)

// number theory, kadane's algorithm, prefix sum
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

const int MAX_NUMS = 1e6;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_NUMS);
class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < size(nums); ++i) {
            int x = nums[i];
            while (x != 1) {
                const auto& p = SPF[x];
                lookup[p].emplace_back(i);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        int best_diff = -ranges::min(nums), best_k = 2;
        for (const auto& [p, idxs] : lookup) {
            int total = 0, j = -1;
            for (const auto& i : idxs) {
                total = max(total - (j != -1 ? prefix[(i - 1) + 1] - prefix[j + 1] : 0), 0) + nums[i];
                if (total > best_diff) {
                    best_diff = total;
                    best_k = p;
                } else if (total == best_diff) {
                    best_k = min(best_k, p);
                }
                j = i;
            }
        }
        return ((static_cast<int64_t>(best_diff) * best_k) % MOD + MOD) % MOD;
    }
};
