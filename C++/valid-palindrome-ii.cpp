// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return validPalindrome(s, left, right - 1) || validPalindrome(s, left + 1, right);
            }
            ++left, --right;
        }
        return true;
    }

private:
    bool validPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
};
