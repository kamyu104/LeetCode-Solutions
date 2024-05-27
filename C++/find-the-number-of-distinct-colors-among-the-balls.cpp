// Time:  O(q)
// Space: O(q)

// freq table
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result(size(queries));
        unordered_map<int, int> lookup, cnt;
        for (int i = 0; i < size(queries); ++i) {
            const int x = queries[i][0], y = queries[i][1];
            if (lookup.count(x)) {
                if (--cnt[lookup[x]] == 0) {
                    cnt.erase(lookup[x]);
                }
            }
            lookup[x] = y;
            ++cnt[lookup[x]];
            result[i] = size(cnt);
        }
        return result;
    }
};
