// Time:  O(loga)
// Space: O(1)

class Solution {
public:
    int smallestFactorization(int a) {
        if (a < 2) {
            return a;
        }
        long result = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            while (a % i == 0) {
                a /= i;
                result = mul * i + result;
                mul *= 10;
            }
        }
        return a == 1 && result <= numeric_limits<int>::max() ? static_cast<int>(result) : 0;
    }
};

