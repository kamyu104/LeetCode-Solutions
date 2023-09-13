// Time:  O(logn)
// Space: O(logn)

// greedy
class Solution {
public:
    string smallestNumber(long long n) {
        string result;
        for (int d = 9; d >= 2; --d) {
            for (; n % d == 0; n /= d) {
                result.push_back('0' + d);
            }
        }
        reverse(begin(result), end(result));
        if (empty(result)) {
            result = "1";
        }
        return n == 1 ? result : "-1";
    }
};
