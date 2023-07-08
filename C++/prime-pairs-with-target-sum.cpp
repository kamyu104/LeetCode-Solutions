// Time:  O(n)
// Space: O(n)

// number theory
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
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
            return spf;  // len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n
        };

        const auto& spf = linear_sieve_of_eratosthenes(n);
        vector<vector<int>> result;
        for (int i = 2; i <= n / 2; ++i) {
            if (spf[i] == i && spf[n - i] == n - i) {
                result.push_back({i, n - i});
            }
        }
        return result;
    }
};
