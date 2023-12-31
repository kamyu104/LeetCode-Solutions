// Time:  O(26 * 3 + n * 3)
// Space: O(26 * 3)

// string, hash table
class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> lookup(26, vector<int>(3));
        int result = 0;
        for (int i = 0, cnt = 0; i < size(s); ++i) {
            ++cnt;
            if (i + 1 != size(s) && s[i + 1] == s[i]) {
                continue;
            }
            auto& curr = lookup[s[i] - 'a'];
            for (int j = 0; j < size(curr); ++j) {
                if (curr[j] < cnt) {
                    swap(cnt, curr[j]);
                }
            }
            cnt = 0;
            result = max({result, curr[0] - 2, min(curr[0] - 1, curr[1]), curr[2]});
        }
        return result ? result : -1;
    }
};
