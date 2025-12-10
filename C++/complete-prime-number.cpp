// Time:  O(logn * sqrt(n))
// Space: O(1)

// prefix sum, number theory
class Solution {
public:
    bool completePrime(int num) {
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

        for (int suffix = 0, base = 1; num; num /= 10, base *= 10) {
            if (!is_prime(num)) {
                return false;
            }
            suffix += (num % 10) * base;
            if (!is_prime(suffix)) {
                return false;
            }
        }
        return true;
    }
};
