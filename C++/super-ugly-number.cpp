// Time:  O(n * k)
// Space: O(n + k)
// DP solution. (596ms)
class Solution2 {
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

// Time:  O(n * klogk)
// Space: O(n + k)
// Heap solution. (1184ms)
class Solution2 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ugly_by_prime;
        vector<int> uglies(n), idx(primes.size());
        uglies[0] = 1;

        for (int k = 0; k < primes.size(); ++k) {
            ugly_by_prime.push({primes[k], k});
        }

        for (int i = 1; i < n; ++i) {
            int min, k;
            tie(min, k) = ugly_by_prime.top();
            uglies[i] = min;

            while (ugly_by_prime.top().first == min) { // worst time: O(klogk)
                tie(min, k) = ugly_by_prime.top();
                ugly_by_prime.pop();
                ugly_by_prime.push({primes[k] * uglies[++idx[k]], k});
            }
        }
    
        return uglies[n - 1]; 
    }
};
