// Time:  O(n + 26)
// Space: O(26)

// freq table, sliding window, two pointers
class Solution {
public:
    int maximumLengthSubstring(string s) {
        static const int COUNT = 2;

        int result = 0;
        vector<int> cnt(26);
        int right = 0, left = 0;
        for (int invalid_cnt = 0; right < size(s); ++right) {
            if (cnt[s[right] - 'a'] == COUNT) {
                ++invalid_cnt;
            }
            ++cnt[s[right] - 'a'];
            if (invalid_cnt) {
                --cnt[s[left] - 'a'];
                if (cnt[s[left++] - 'a'] == COUNT) {
                    --invalid_cnt;
                }
            }
        }
        return right - left;
    }
};

// Time:  O(n + 26)
// Space: O(26)
// freq table, sliding window, two pointers
class Solution2 {
public:
    int maximumLengthSubstring(string s) {
        static const int COUNT = 2;

        int result = 0;
        vector<int> cnt(26);
        for (int right = 0, left = 0; right < size(s); ++right) {
            ++cnt[s[right] - 'a'];
            while (cnt[s[right] - 'a'] > COUNT) {
                --cnt[s[left++] - 'a'];
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
