// Time:  O(n + rlogr)
// Space: O(r)

// number theory, mobius function, principle of inclusion-exclusion
class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
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

        // https://www.geeksforgeeks.org/program-for-mobius-function-set-2/
        const auto& mobius = [](const auto& spf) {  // Time: O(n), Space: O(n)
            vector<int> mu(size(spf));
            for (int i = 1; i < size(mu); ++i) {
                mu[i] = i == 1 ? 1 : (spf[i / spf[i]] == spf[i] ? 0 :  -mu[i / spf[i]]);
            }
            return mu;
        };

        const auto& mx = max(ranges::max(nums), maxVal);
        const auto& spf = linear_sieve_of_eratosthenes(mx);
        const auto& mu = mobius(spf);
        vector<int> cnt(mx + 1);
        for (const auto& x : nums) {
            ++cnt[x];
        }
        vector<int> multiple_cnt(mx + 1);
        for (int i = 1; i <= mx; ++i) {
            for (int j = i; j <= mx; j += i) {
                multiple_cnt[i] += cnt[j];
            }
        }
        vector<int> coprime_cnt(mx + 1);
        for (int i = 1; i <= mx; ++i) {
            if (!mu[i] * multiple_cnt[i]) {
                continue;
            }
            for (int j = i; j <= mx; j += i) {
                coprime_cnt[j] += mu[i] * multiple_cnt[i];
            }
        }
        int result = 0;
        for (int i = 1; i <= mx; ++i) {
            const int c = size(nums) - coprime_cnt[i];
            if (cnt[i]) {
                result = max(result, i - ((i != 1) ? (c - 1) : 0));
            } else if (i <= maxVal) {
                result = max(result, i - max(c, 1));
            }
        }
        return result;
    }
};
