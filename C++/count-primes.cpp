// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        auto num = n / 2;
        vector<int> is_prime(n, true);

        for (int i = 3; i * i < n; i += 2) {
            if (!is_prime[i]) {
                continue;
            }

            for (int j = i * i; j < n; j += 2 * i) {
                if (!is_prime[j]) {
                    continue;
                }

                --num;
                is_prime[j] = false;
            }
        }

        return num;
    }
};
