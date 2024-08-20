// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int result = 0;
        for (int right = 0, left = 0, cnt = 0; right < size(s); ++right) {
            cnt += s[right] == '1' ? 1 : 0;
            while (!(cnt <= k || (right - left + 1) - cnt <= k)) {
                cnt -= s[left++] == '1' ? 1 : 0;
            }
            result += right - left + 1;
        }
        return result;
    }
};
