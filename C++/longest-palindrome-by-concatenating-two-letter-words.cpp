// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto& x : words) {
            ++cnt[x];
        }
        int result = 0, remain = 0;
        for (const auto& [x, c] : cnt) {
            const string mirror(crbegin(x), crend(x));
            if (x == mirror) {
                result += c / 2;
                remain |= c % 2;
            } else if (x < mirror && cnt.count(mirror)) {
                result += min(c, cnt[mirror]);
            }
        }
        return result * 4 + remain * 2;
    }
};
