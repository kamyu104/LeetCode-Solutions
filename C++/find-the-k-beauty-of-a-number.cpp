// Time:  O(logn)
// Space: O(logn)

// sliding window
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int result = 0;
        const auto& s = to_string(num);
        const int base = pow(10, k - 1);
        for (int i = 0, curr = 0; i < size(s); ++i) {
            if (i - k >= 0) {
                curr -= (s[i - k] - '0') * base;
            }
            curr = curr * 10 + (s[i] - '0');
            if (i + 1 >= k) {
                result += static_cast<int>(curr && num % curr == 0);
            }
        }
        return result;
    }
};
