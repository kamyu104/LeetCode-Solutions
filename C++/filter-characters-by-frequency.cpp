// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    string filterCharacters(string s, int k) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        string result;
        for (const auto& x : s) {
            if (cnt[x - 'a'] < k) {
                result.push_back(x);
            }
        }
        return result;
    }
};
