// Time:  O(n)
// Space: O(1)

// string, bitmasks
class Solution {
public:
    bool isPalindromic(string s) {
        const auto& check = [](char i, char j) {
            const auto& reverse = [](char x) {
                char result = 0;
                for (int _ = 0 ; _ < 8; ++_) {
                    result  = (result << 1) | (x & 1);
                    x >>= 1;
                }
                return result;
            };

            return i == reverse(j);
        };
    
        for (int i = 0; i < (size(s) + 1) / 2; ++i) {
            if (!check(s[i], s[size(s) - 1 - i])) {
                return false;
            }
        }
        return true;
    }
};
