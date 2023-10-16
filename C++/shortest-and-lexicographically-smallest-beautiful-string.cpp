// Time:  O(n^2)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const auto& check = [&](int l1, int r1, int l2, int r2) {
            const int c1 = r1 - l1 + 1, c2 = r2 -l2 + 1;
            if (c1 > c2) {
                return false;
            }
            if (c1 < c2) {
                return true;
            }
            for (int i = 0; i < c1; ++i) {
                if (s[l1 + i] != s[l2 + i]) {
                    return s[l1 + i] < s[l2 + i];
                }
            }
            return false;
        };
        
        vector<int> result = {};
        for (int right = 0, left = 0, curr = 0; right < size(s); ++right) {
            curr += static_cast<int>(s[right] == '1');
            while (curr == k + 1) {
                curr -= static_cast<int>(s[left++] == '1');
            }
            while (left < size(s) && s[left] == '0') {
                ++left;
            }
            if (curr == k) {
                if (empty(result) || check(left, right, result[0], result[1])) {
                    result = {left, right};
                }
            }
        }
        return !empty(result) ? s.substr(result[0], result[1] - result[0] + 1) : "";
    }
};
