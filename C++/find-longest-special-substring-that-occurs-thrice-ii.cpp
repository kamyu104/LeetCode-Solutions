// Time:  O(n * 3)
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
            const int x = s[i] - 'a';
            for (int j = 0; j < size(lookup[x]); ++j) {
                if (lookup[x][j] < cnt) {
                    swap(cnt, lookup[x][j]);
                }
            }
            cnt = 0;
            result = max({result, lookup[x][0] - 2, min(lookup[x][0] - 1, lookup[x][1]), lookup[x][2]});
        }
        return result ? result : -1;
    }
};
