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
            for (int i = 0; i < primes.size(); ++i) {
                if (min_val == ugly_by_prime[i]) {
                    ugly_by_prime[i] = primes[i] * uglies[++idx[i]];
                }
            }
        }
    
        return uglies[n - 1]; 
    }
};
