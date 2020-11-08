// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        for (const auto& c : s) {
            ++count[c - 'a'];
        }
        int result = 0;
        unordered_set<int> lookup;
        for (int i = 0; i < 26; ++i) {
            for (int c = count[i]; c > 0; --c, ++result) {
                if (!lookup.count(c)) {
                    lookup.emplace(c);
                    break;
                }
            }
        }
        return result;
    }
};
