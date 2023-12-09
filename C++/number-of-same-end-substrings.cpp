// Time:  O(26 * (n + q))
// Space: O(26 * n)

// freq table, prefix sum
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(1, vector<int>(26));
        for (int i = 0; i < size(s); ++i) {
            prefix.emplace_back(prefix.back());
            ++prefix.back()[s[i] - 'a'];
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const int l = queries[i][0], r = queries[i][1];
            for (int j = 0; j < 26; ++j) {
                const int cnt = prefix[r + 1][j] - prefix[l][j];
                result[i] += (1 + cnt) * cnt / 2;
            }
        }
        return result;
    }
};
