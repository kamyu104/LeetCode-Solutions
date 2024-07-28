// Time:  precompute:  O(sqrt(r))
//        runtime:     O(logr + log(sqrt(r))) = O(logr)
// Space: O(sqrt(r))

// number theory, binary search
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
};

const int MAX_R = 1e9;
const auto& PRIMES = linear_sieve_of_eratosthenes(sqrt(MAX_R));
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        const auto& count = [](int x) {
            return x - distance(cbegin(PRIMES), upper_bound(cbegin(PRIMES), cend(PRIMES), sqrt(x)));
        };

        return count(r) - count(l - 1);
    }
};
