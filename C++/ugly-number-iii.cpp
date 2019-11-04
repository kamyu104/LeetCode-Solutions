// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int64_t lcm_a_b = lcm(a, b), lcm_b_c = lcm(b, c), lcm_c_a = lcm(c, a);
        int64_t lcm_a_b_c = lcm(lcm_a_b, lcm_b_c);
        int64_t left = 1, right = 2 * 1e9;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (count(mid, a, b, c,
                      lcm_a_b, lcm_b_c, lcm_c_a, lcm_a_b_c) >= n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int64_t count (int64_t x,
                   int64_t a, int64_t b, int64_t c,
                   int64_t lcm_a_b, int64_t lcm_b_c, int64_t lcm_c_a,
                   int64_t lcm_a_b_c) {
        return x / a + x / b + x / c - (x / lcm_a_b + x / lcm_b_c + x / lcm_c_a) + x / lcm_a_b_c;
    }

    int64_t gcd(int64_t a, int64_t b) {
        while (b != 0) {
            const auto tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    
    int64_t lcm(int64_t a, int64_t b) {
        return a / gcd(a, b) * b;
    }
};
