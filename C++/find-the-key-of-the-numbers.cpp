// Time:  O(d), d = 4
// Space: O(1)

// math
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        static const int L = 4;

        int result = 0;
        for (int _ = 0, base = pow(10, L - 1); _ < L; ++_, base /= 10) {
            result = result * 10 + min({num1 / base % 10, num2 / base % 10, num3 / base % 10});
        }
        return result;
    }
};
