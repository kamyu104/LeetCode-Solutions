// Time:  precompute: O(sqrt(r))
//        runtime:    O(sqrt(n) / logn)
// Space: O(sqrt(r))

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

const int MAX_N = 1e9;
const auto& PRIMES = linear_sieve_of_eratosthenes(sqrt(MAX_N));
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }
        int x = value;
        for (const auto& p : PRIMES) {
            if (p * p > value) {
                break;
            }
            if (value % p == 0) {
                x = p;
                break;
            }
        }
        if (value - x - 2 * (index - 1) < 2) {
            return -1;
        }
        return index != n - 1 ? value + x + 2LL * ((n - 1) - index - 1) : value;
    }
};
