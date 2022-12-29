// Time:  O(n)
// Space: O(1)

// sliding window, two pointers
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }
        if (*min_element(cbegin(cnt), cend(cnt)) < k) {
            return -1;
        }
        int result = 0;
        for (int right = 0, left = 0; right < size(s); ++right) {
            --cnt[s[right] - 'a'];
            while (cnt[s[right] - 'a'] < k) {
                ++cnt[s[left++] - 'a'];
            }
            result = max(result, right - left + 1);
        }
        return size(s) - result;
    }
};
