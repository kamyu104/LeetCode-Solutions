// Time:  O(10^(2n))
// Space: O(n)

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i) {
            auto candidate = buildPalindrome(i);
            for (long long j = upper; j * j >= candidate; --j) {
                if (candidate % j == 0) {
                    return candidate % 1337;
                }
            }
        }
        return -1;
    }

private:
    long long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoll(to_string(n) + s);
    }
};
