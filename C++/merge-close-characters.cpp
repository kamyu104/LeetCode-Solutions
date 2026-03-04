// Time:  O(n + 26)
// Space: O(26)

// simulation, freq table, two pointers
class Solution {
public:
    string mergeCharacters(string s, int k) {
        string result;
        vector<int> cnt(26);
        for (const auto& x : s) {
            if (cnt[x - 'a']) {
                continue;
            }
            ++cnt[x - 'a'];
            result.push_back(x);
            if (size(result) >= k + 1) {
                --cnt[result[size(result) - (k + 1)] - 'a'];
            }
        }
        return result;
    }
};
