// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (size(word1) != size(word2)) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (const auto& c : word1) {
            ++cnt1[c - 'a'];
        }
        for (const auto& c : word2) {
            ++cnt2[c - 'a'];
        }
        unordered_map<int, int> diff;
        for (int i = 0; i < size(cnt1); ++i) {
            if (!cnt1[i] && !cnt2[i]) {
                continue;
            }
            if (!cnt1[i] || !cnt2[i]) {
                return false;
            }
            ++diff[cnt1[i]];
            --diff[cnt2[i]];
        }
        return all_of(cbegin(diff), cend(diff),
                      [](const auto& kvp) {
                          return kvp.second == 0;
                      });
    }
};
