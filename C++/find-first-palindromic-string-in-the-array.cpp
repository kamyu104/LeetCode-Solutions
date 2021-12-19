// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& w : words) {
            if (is_palindrome(w)) {
                return w;
            }
        }
        return "";
    }

private:
    bool is_palindrome(const string& s) {
        int i = 0, j = size(s) - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
