// Time:  O(logn)
// Space: O(1)

// greedy
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int total = 0;
        for (int64_t m = n; m; m /= 10) {
            total += m % 10;
        }
        int64_t m = n, l = 0;
        while (total > target) {
            do {
                total -= m % 10;
                m /= 10;
                ++l;
            } while (m % 10 == 9);
            ++total, ++m;
        }   
        return m * pow(10, l) - n;
    }
};
