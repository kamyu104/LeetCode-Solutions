// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int countVowelStrings(int n) {
        return nCr(n + 4, 4);  // H(5, n) = C(n+5-1, n) = C(n+4, 4)
    }

private:
    uint64_t nCr(int n, int r) {  // Time: O(n), Space: O(1)
        if (n - r < r) {
            return nCr(n, n - r);
        }
        uint64_t c = 1;
        for (int k = 1; k <= r; ++k) {
            c *= n - k + 1;
            c /= k;
        }
        return c;
    }
};
