// Time:  precompute: O(r)
//        runtime:    O(min(n / logn, sqrt(s)))
// Space: O(r)

// number theory, greedy
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
    return primes;
}

const int MAX_N = 1e6;
const auto& PRIMES = linear_sieve_of_eratosthenes(MAX_N);
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> result;
        for (const auto& x : PRIMES) {
            if (x > n || s - x < 0) {
                break;
            }
            s -= x;
            result.emplace_back(x);
        }
        return result;
    }
};
