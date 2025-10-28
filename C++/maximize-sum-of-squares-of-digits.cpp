// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) {
            return "";
        }

        string result(num, '0');
        const int q = sum / 9;
        const int r = sum % 9;
        for (int i = 0; i < q; ++i) {
            result[i] = '9';
        }
        if (r) {
            result[q] = '0' + r;
        }
        return result;
    }
};
