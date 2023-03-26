// Time:  precompute: O(sqrt(MAX_N))
//        runtime:    O(m + nlog(logn)), m = len(nums), n = max(nums)
// Space: O(sqrt(MAX_N))

// number theory
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
    return primes;  // len(primes) = O(n/(logn-1)), reference: https://math.stackexchange.com/questions/264544/how-to-find-number-of-prime-numbers-up-to-to-n
}

const int MAX_N = 1000;
const auto& PRIMES = linear_sieve_of_eratosthenes(sqrt(MAX_N));
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> result;
        for (auto x : unordered_set<int>(cbegin(nums), cend(nums))) {  // Time: O(n/p1 + n/p2 + ... + n/pk) = O(n * (1/p1 + 1/p2 + ... + 1/pk)) = O(nlog(logn))
            for (const auto& p : PRIMES) {
                if (p > x) {
                    break;
                }
                if (x % p) {
                    continue;
                }
                result.emplace(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
            if (x != 1) {  // x is a prime
                result.emplace(x);
            }
        }
        return size(result);
    }
};
