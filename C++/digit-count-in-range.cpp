// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return digitsCount(high, d) - digitsCount(low - 1, d);
    }

private:
    int digitsCount(int n, int k) {
        int result = 0;
        int64_t pivot = 1;
        while (n >= pivot) {
            result += n / (10 * pivot) * pivot +
                      min(pivot, max(n % (10 * pivot) - k * pivot + 1, 0l));
            if (k == 0) {
                 result -= pivot;
            }
            pivot *= 10;
        }
        return result;
    }
};
