// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - is_palindrome(s) - s.empty();
    }

private:
    bool is_palindrome(const string& s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
