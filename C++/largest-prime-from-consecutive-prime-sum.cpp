// Time:  precompute: O(sqrt(r) * sqrt(r)) = O(r)
//        runtime:    O(logp), p = len(PRIMES)
// Space: O(sqrt(r))

// precompute, number theory, binary search
const auto& is_prime = [](int n) {
    if (n <= 1 || (n != 2 && n % 2 == 0)) {
        return false;
    }
    for (int i = 3; i <= n; i += 2) {
        if (i * i > n) {
            break;
        }
        if (n % i == 0) {
            return false;
        }
    }
    return true;
};

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
    return pair(primes, spf);
};

const auto& precompute = [](int n, int sqrt_n) {
    const auto& [primes, spf] = linear_sieve_of_eratosthenes(sqrt_n);
    vector<int> result = {0};
    int total = 0;
    for (const auto& p : primes) {
        total += p;
        if (total > n) {
            break;
        }
        if ((total < size(spf) && spf[total] == total) || is_prime(total)) {
            result.emplace_back(total);
        }
    }
    return result;
};

const int MAX_NUM = 5e5;
const int SQRT_MAX_NUM = 2729;  // by precomputation
const auto& PRIMES = precompute(MAX_NUM, SQRT_MAX_NUM);
class Solution {
public:
    int largestPrime(int n) {
        return *prev(upper_bound(cbegin(PRIMES), cend(PRIMES), n));
    }
};
