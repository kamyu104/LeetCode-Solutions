// Time:  O(m + n)
// Space: O(m + n)

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt;
        for (const auto& w : words1) {
            ++cnt[w];
        }
        for (const auto& w : words2) {
            if (cnt[w] < 2) {
                --cnt[w];
            }
        }
        int result = 0;
        for (const auto& [_, v] : cnt) {
            if (v == 0) {
                ++result;
            }
        }
        return result;
    }
};
