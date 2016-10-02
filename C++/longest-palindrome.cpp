// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (auto c = 'A'; c <= 'z'; ++c) {
            odds += count(s.cbegin(), s.cend(), c) & 1;
        }
        return s.length() - odds + (odds > 0);
    }
};
