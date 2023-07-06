// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int result = 0, left = 0;
        vector<int> lookup(26, -1);
        for (int right = 0; right < size(s); ++right) {
            if (lookup[s[right] - 'a'] >= left) {
                left = lookup[s[right] - 'a'] + 1;
            }
            lookup[s[right] - 'a'] = right;
            result += (right - left + 1);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// two pointers, sliding window
class Solution2 {
public:
    int numberOfSpecialSubstrings(string s) {
        int result = 0, left = 0;
        vector<bool> lookup(26);
        for (int right = 0; right < size(s); ++right) {
            while (lookup[s[right] - 'a']) {
                lookup[s[left++] - 'a'] = false;
            }
            lookup[s[right] - 'a'] = true;
            result += (right - left + 1);
        }
        return result;
    }
};
