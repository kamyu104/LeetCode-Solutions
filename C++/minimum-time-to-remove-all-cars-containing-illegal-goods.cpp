// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int minimumTime(string s) {
        int left = 0;
        int result = left + (size(s) - 0);
        for (int i = 1; i <= size(s); ++i) {
            left = min(left + 2 * (s[i - 1] == '1'), i);
            result = min(result, left + static_cast<int>(size(s)) - i);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dp
class Solution2 {
public:
    int minimumTime(string s) {
        vector<int> right(size(s) + 1);
        for (int i = size(s) - 1; i >= 0; --i) {
            right[i] = min(right[i + 1] + 2 * (s[i] == '1'), static_cast<int>(size(s)) - i);
        }
        int left = 0;
        int result = left + right[0];
        for (int i = 1; i <= size(s); ++i) {
            left = min(left + 2 * (s[i - 1] == '1'), i);
            result = min(result, left + right[i]);
        }
        return result;
    }
};
