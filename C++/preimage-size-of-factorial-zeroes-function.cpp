// Time:  O((logn)^2)
// Space: O(1)

class Solution {
public:
    int preimageSizeFZF(int K) {
        const int p = 5;
        int left = 0, right = p * K;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (countOfFactorialPrimes(mid, p) >= K) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (countOfFactorialPrimes(left, p) != K) {
            return 0;
        }
        return (left / p + 1) * p - left;
    }

private:
    int countOfFactorialPrimes(int n, int p) {
        int cnt = 0;
        for (; n > 0; n /= p) {
            cnt += n / p;
        }
        return cnt;
    }
};
