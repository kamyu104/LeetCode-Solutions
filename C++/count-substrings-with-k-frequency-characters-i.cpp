// Time:  O(n + 26)
// Space: O(26)

// freq table, two pointers, sliding window
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        const auto& count = [&]() {
            int result = 0;
            vector<int> cnt(26);
            for (int right = 0, left = 0; right < size(s); ++right) {
                ++cnt[s[right] - 'a'];
                for (; cnt[s[right] - 'a'] == k; ++left) {
                    --cnt[s[left] - 'a'];
                }
                result += right - left + 1;
            }
            return result;
        };

        return (size(s) + 1) * size(s) / 2 - count();
    }
};
