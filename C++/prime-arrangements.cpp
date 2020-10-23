// Time:  O(n/2 + n/3 + ... + n/p) = O(nlog(logn)), see https://mathoverflow.net/questions/4596/on-the-series-1-2-1-3-1-5-1-7-1-11
// Space: O(n)

class Solution {
public:    
    int numPrimeArrangements(int n) {
        int cnt = count_primes(n);
        return static_cast<uint64_t>(factorial(cnt)) * factorial(n - cnt) % MOD;
    }

private:
    int count_primes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> is_primes((n + 1) / 2, true);
        int cnt = is_primes.size();
        for (int i = 3; i * i <= n; i += 2) {
            if (!is_primes[i / 2]) {
                continue;
            }
            for (int j = i * i; j <= n; j += 2 * i) {
                if (!is_primes[j / 2]) {
                    continue;
                }
                --cnt;
                is_primes[j / 2] = false;
            }
        }
        return cnt;
    }

    int factorial(int n) {
        int result = 1ull;
        for (int i = 2; i <= n; ++i) {
            result = (static_cast<uint64_t>(result) * i) % MOD;
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};
