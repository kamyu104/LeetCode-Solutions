// Time:  O(n^2 * sqrt(r))
// Space: O(n^2)

// number theory, quick select
class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        static const int COUNT = 3;

        const auto& is_prime = [](int64_t n) {
            if (n == 1) {
                return false;
            }
            if (n == 2 || n == 3) {
                return true;
            }
            if (n % 2 == 0 || n % 3 == 0) {
                return false;
            }
            for (int64_t i = 5; i < n; i += 6) {
                if (i * i > n) {
                    break;
                }
                if (n % i == 0 || n % (i + 2) == 0) {
                    return false;
                }
            }
            return true;
        };

        unordered_set<int64_t> primes_set;
        for (int i = 0; i < size(s); ++i) {
            int64_t curr = 0;
            for (int j = i; j < size(s); ++j) {
                curr = curr * 10 + (s[j] - '0');
                if (is_prime(curr)) {
                    primes_set.emplace(curr);
                }
            }
        }
        vector<int64_t> primes(cbegin(primes_set), cend(primes_set));
        const int d = min(static_cast<int>(size(primes)), 3);
        nth_element(begin(primes), begin(primes) + d, end(primes), greater<int64_t>());
        return accumulate(cbegin(primes), cbegin(primes) + d, 0ll);
    }
};
