// Time:  O(n)
// Space: O(n)
//
// Description:
//
// Count the number of prime numbers less than a non-negative number, n
//
// Hint: The number n could be in the order of 100,000 to 5,000,000.
//

class Solution {
public:
    int countPrimes(int n) {
        if (2 >= n) {
            return 0;
        }
        bool* primes = new bool[n];
        for (int i = 2; i < n; ++i)
            primes[i] = true;

        int sqr = sqrt(n - 1);
        int sum = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                ++sum;
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        delete[] primes;

        return sum;
    }
};
