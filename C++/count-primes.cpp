// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<int> is_prime(n / 2, true);
        auto cnt = is_prime.size();
        for (int i = 3; i * i < n; i += 2) {
            if (!is_prime[i / 2]) {
                continue;
            }
            for (int j = i * i; j < n; j += 2 * i) {
                if (!is_prime[j / 2]) {
                    continue;
                }
                --cnt;
                is_prime[j / 2] = false;
            }
        }
        return cnt;
    }
};
