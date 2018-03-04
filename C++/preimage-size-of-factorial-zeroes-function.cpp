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
        return countOfFactorialPrimes(left, p) == K ? p : 0;
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
