// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findDerangement(int n) {
        static const int M = 1000000007;
        long long mul = 1, sum = 0;
        for (int i = n; i >= 0; --i) {
            sum = (sum + M + (i % 2 == 0 ? 1 : -1) * mul) % M;
            mul = (mul * i) % M;
        }
        return static_cast<int>(sum);
    }
};

