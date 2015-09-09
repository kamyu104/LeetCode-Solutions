// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int numSquares(int n) {
        vector<int> num(n + 1, numeric_limits<int>::max());
        num[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i - 1, k = 1; j >= 0; ++k, j = i - k * k) {
                num[i] = min(num[i], num[j] + 1);
            }
        }
        return num[n];
    }
};
