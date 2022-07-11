// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countPrimes(int n) {
        return size(linear_sieve_of_eratosthenes(n - 1));
    }

private:
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
};

// Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn)), see https://mathoverflow.net/questions/4596/on-the-series-1-2-1-3-1-5-1-7-1-11
// Space: O(n)
class Solution2 {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<int> is_prime(n / 2, true);
        auto cnt = is_prime.size();
        for (int i = 3; i * i < n; i += 2) {
            if (!is_prime[i / 2]) {
                continue;
            }
            for (int j = i * i; j < n; j += 2 * i) {
                if (!is_prime[j / 2]) {
                    continue;
                }
                --cnt;
                is_prime[j / 2] = false;
            }
        }
        return cnt;
    }
};
