// Time:  O(s * logn), s is the times of simulation
// Space: O(max_n^0.5)

// number theory, simulation
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

const int MAX_N = 1e5;
const auto& PRIMES = linear_sieve_of_eratosthenes(static_cast<int>(sqrt(MAX_N)));
class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int curr = n, new_n =0;
            for (const auto& p : PRIMES) {
                if (p * p > curr) {
                    continue;
                }
                while (curr % p == 0) {
                    curr /= p;
                    new_n += p;
                }
            }
            if (curr > 1) {  // curr is a prime
                new_n += curr;
            }
            if (new_n == n) {
                break;
            }
            n = new_n;
        }
        return n;
    }
};
