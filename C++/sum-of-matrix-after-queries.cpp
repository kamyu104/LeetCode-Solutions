// Time:  O(n + q)
// Space: O(n)

// hash table
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<vector<bool>> lookup(2, vector<bool>(n));
        vector<int> cnt(2);
        int64_t result = 0;
        for (int i = size(queries) - 1; i >= 0; --i) {
            const int t = queries[i][0], idx = queries[i][1], v = queries[i][2];
            if (lookup[t][idx]) {
                continue;
            }
            lookup[t][idx] = true;
            ++cnt[t];
            result += v * (n - cnt[t ^ 1]);
        }
        return result;
    }
};
