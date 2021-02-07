// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = size(s) - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                break;
            }
            auto c = s[left];
            while (left <= right) {
                if (s[left] != c) {
                    break;
                }
                ++left;
            }
            while (left <= right) {
                if (s[right] != c) {
                    break;
                }
                --right;
            }
        }
        return right - left + 1;
    }
};
