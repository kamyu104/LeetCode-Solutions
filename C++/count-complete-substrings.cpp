// Time:  O(26 + d * n), d = len(set(word))
// Space: O(26)

// freq table, two pointers
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        const int d = size(unordered_set<char>(cbegin(word), cend(word)));
        int result = 0, valid = 0;
        vector<int> cnt(26);
        for (int c = 1; c <= d; ++c) {
            int left = 0;
            for (int right = 0; right < size(word); ++right) {
                const int curr = ++cnt[word[right] - 'a'];
                valid += curr == k ? 1 : curr == k + 1 ? -1 : 0;
                if (right - 1 >= 0 && abs(word[right] - word[right - 1]) > 2) {
                    while (left < right) {
                        const int curr = cnt[word[left++] - 'a']--;
                        valid -= curr == k ? 1 : curr == k + 1 ? -1 : 0;
                    }
                } else if (right - left + 1 == c * k + 1) {
                    const int curr = cnt[word[left++] - 'a']--;
                    valid -= curr == k ? 1 : curr == k + 1 ? -1 : 0;
                }
                if (valid == c) {
                    ++result;
                }
            }
            while (left < size(word)) {
                const int curr = cnt[word[left++] - 'a']--;
                valid -= curr == k ? 1 : curr == k + 1 ? -1 : 0;
            }
        }
        return result;
    }
};
