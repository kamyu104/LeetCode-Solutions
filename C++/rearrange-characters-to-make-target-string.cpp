// Time:  O(n + m)
// Space: O(1)

// freq table
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt1(26), cnt2(26);
        for (const auto& c : s) {
            ++cnt1[c - 'a'];
        }
        for (const auto& c : target) {
            ++cnt2[c - 'a'];
        }
        int result = numeric_limits<int>::max();
        for (int i = 0; i < size(cnt2); ++i) {
            if (!cnt2[i]) {
                continue;
            }
            result = min(result, cnt1[i] / cnt2[i]);
        }
        return result;
    }
};
