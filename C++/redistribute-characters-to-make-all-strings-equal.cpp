// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26);
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        return all_of(cbegin(cnt), cend(cnt),
                      [&words](int c) {
                          return c % size(words) == 0;
                      });
    }
};
