// Time:  O(logn)
// Space: O(1)

// math, bitmasks
class Solution {
public:
    string kthLuckyNumber(int k) {
        string result;
        for (++k; k != 1; k >>= 1) {
            result.push_back(k & 1 ? '7' : '4');
        }
        reverse(begin(result), end(result));
        return result;
    }
};
