// Time:  O(n + 26)
// Space: O(26)

// two pointers, sliding window, freq table
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> cnt(26);
        int curr = 0;
        for (const auto& x : word2) {
            if (cnt[x - 'a']++ == 0) {
                ++curr;
            }
        }
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(word1); ++right) {
            if (--cnt[word1[right] - 'a'] == 0) {
                --curr;
            }
            for (; !curr; ++left) {
                result += size(word1) - right;
                if (cnt[word1[left] - 'a']++ == 0) {
                    ++curr;
                }
            }
        }
        return result;
    }
};
