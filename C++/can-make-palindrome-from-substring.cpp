// Time:  O(m + n), m is the number of queries, n is the length of s
// Space: O(n)

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        static const int CHARSET_SIZE = 26;
        vector<int> curr(CHARSET_SIZE);
        vector<vector<int>> count(1, vector<int>(CHARSET_SIZE));
        for (const auto& c : s) {
            ++curr[c - 'a'];
            count.emplace_back(curr);
        }
        vector<bool> result;
        for (const auto& query : queries) {
            int left = query[0], right = query[1], k = query[2];
            int total = 0;
            for (int i = 0; i < CHARSET_SIZE; ++i) {
                total += (count[right + 1][i] - count[left][i]) % 2;
            }
            result.emplace_back(total / 2 <= k);
        }
        return result;
    }
};
