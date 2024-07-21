// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        return accumulate(cbegin(cnt), cend(cnt), 0, [](const auto& accu, const auto& x) {
            return accu + (x ? 2 - x % 2 : 0);
        });
    }
};
