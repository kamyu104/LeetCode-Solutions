// Time:  O(n * k)
// Space: O(n + k)

// DP solution.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglies{1}, ugly_by_prime(primes), idx(primes.size());
        while (uglies.size() < n) {
            int min_val = *min_element(ugly_by_prime.begin(), ugly_by_prime.end());
            uglies.emplace_back(min_val);
            for (int k = 0; k < primes.size(); ++k) {
                if (min_val == ugly_by_prime[k]) {
                    ugly_by_prime[k] = primes[k] * uglies[++idx[k]];
                }
            }
        }
    
        return uglies[n - 1]; 
    }
};
