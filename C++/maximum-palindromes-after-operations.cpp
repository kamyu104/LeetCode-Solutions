// Time:  O(n * l + nlogn)
// Space: O(n)

// freq table, greedy, sort
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cnt(26);
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        int curr = 0;
        for (const auto& x : cnt) {
             curr += x / 2;
        }
        vector<int> lengths(size(words));
        for (int i = 0; i < size(lengths); ++i) {
            lengths[i] = size(words[i]);
        }
        sort(begin(lengths), end(lengths));
        for (int i = 0; i < size(lengths); ++i) {
            curr -= lengths[i] / 2;
            if (curr < 0) {
                return i;
            }
        }
        return size(words);
    }
};
