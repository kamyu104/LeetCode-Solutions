// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        static const int M = 1000000007;
        const uint64_t a = A, b = B;
        const auto lcm = a * b / gcd(a, b);

        auto left = min(a, b), right = max(a, b) * N;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(A, B, N, lcm, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left % M;
    }

private:
    bool check(uint64_t a, uint64_t b, uint64_t N, uint64_t lcm, uint64_t target) {
        return target / a + target / b - target / lcm >= N;
    }

    uint64_t gcd(uint64_t a, uint64_t b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};
