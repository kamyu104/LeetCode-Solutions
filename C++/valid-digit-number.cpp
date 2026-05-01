// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    bool validDigit(int n, int x) {
        bool result = false;
        for (; n; n /= 10) {
            if (n % 10 != x) {
                continue;
            }
            if (!(n / 10)) {
                return false;
            }
            result = true;
        }
        return result;
    }
};

// Time:  O(logn)
// Space: O(1)
// math
class Solution2 {
public:
    bool validDigit(int n, int x) {
        const auto& s = to_string(n);
        x += '0';
        return x != s[0] && s.find(x) != string::npos;
    }
};
