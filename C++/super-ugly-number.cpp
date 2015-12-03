// Time:  O(n * k)
// Space: O(n + k)

// DP solution. (596ms)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglies(n), ugly_by_prime(primes), idx(primes.size());
        uglies[0] = 1;

        for (int i = 1; i < n; ++i) {
            int min_val = *min_element(ugly_by_prime.begin(), ugly_by_prime.end());
            uglies[i] = min_val;
            for (int k = 0; k < primes.size(); ++k) {
                if (min_val == ugly_by_prime[k]) {
                    ugly_by_prime[k] = primes[k] * uglies[++idx[k]];
                }
            }
        }
    
        return uglies[n - 1]; 
    }
};
