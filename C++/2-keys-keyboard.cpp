// Time:  O(sqrt(n))
// Space: O(1)

class Solution {
public:
    int minSteps(int n) {
        auto result = 0;
        // the answer is the sum of prime factors
        for (auto p = 2 ; p * p <= n; ++p) {
            while (n % p == 0) {
                result += p;
                n /= p;
            }
        }
        result += (n > 1) ? n : 0;
        return result;
    }
};
